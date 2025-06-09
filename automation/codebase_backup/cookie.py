import os
import sys
import json
import requests
from pathlib import Path
import argparse
import time
from requests.exceptions import RequestException
import subprocess

class CookieAutomation:
    def __init__(self):
        self.config_file = Path.home() / '.cookie_config.json'
        self.api_key = None
        self.api_endpoint = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent"
        self.source_files = {
            'codegen': 'codegen.cpp',
            'ast': 'ast.c',
            'ast_header': 'ast.h',
            'runtime': 'runtime.c',
            'parser': 'parser.y',
            'lexer': 'lexer.l'
        }
        self.automation_dir = Path(__file__).parent.parent
        self.backup_dir = self.automation_dir / 'codebase_backup'
        self.max_retries = 5
        self.retry_delay = 5
        self.load_config()
        self.feature_description = None
        self.file_contents = {}

    def load_config(self):
        """Load API key from config file"""
        if self.config_file.exists():
            with open(self.config_file) as f:
                config = json.load(f)
                self.api_key = config.get('api_key')
        else:
            self.api_key = None

    def save_config(self, api_key):
        """Save API key to config file"""
        if not api_key.startswith('AIza'):
            print("Error: Invalid API key format. API key should start with 'AIza'")
            return False

        config = {
            'api_key': api_key,
            'api_endpoint': self.api_endpoint
        }
        with open(self.config_file, 'w') as f:
            json.dump(config, f, indent=2)
        self.api_key = api_key
        return True

    def setup(self):
        """Initial setup for API key"""
        if self.api_key:
            print("API key already exists. Use --reset to set a new key.")
            return

        print("Welcome to Cookie Automation!")
        print("Please enter your Google Gemini API key (should start with 'AIza'):")
        api_key = input().strip()
        
        if not api_key:
            print("Error: API key cannot be empty")
            return

        if self.save_config(api_key):
            print("API key saved successfully!")
            print("Testing API key...")
            if self.test_api_key():
                print("API key is valid and working!")
            else:
                print("Warning: Could not verify API key. Please check if it's correct.")

    def test_api_key(self):
        """Test if the API key is valid"""
        test_message = "What are the main features of Go language?"
        response = self.send_to_api(test_message)
        if response and 'candidates' in response:
            print("\nAPI Test Response:")
            print(response['candidates'][0]['content']['parts'][0]['text'])
            return True
        return False

    def backup_codebase(self):
        """Create a backup of the original codebase"""
        try:
            # Create backup directory if it doesn't exist
            self.backup_dir.mkdir(exist_ok=True)
            
            # First check if backup files already exist
            backup_exists = all((self.backup_dir / file).exists() for file in self.source_files.values())
            
            if backup_exists:
                print("Backup files already exist, skipping backup...")
                return
            
            # Create backup only if files don't exist
            for file in self.source_files.values():
                src_path = Path.cwd() / file
                if src_path.exists():
                    dst_path = self.backup_dir / file
                    with open(src_path, 'r') as src, open(dst_path, 'w') as dst:
                        dst.write(src.read())
                    print(f"Backed up {file} to {dst_path}")
                else:
                    print(f"Warning: Source file {file} not found")
            
            print("Codebase backed up successfully!")
        except Exception as e:
            print(f"Error during backup: {e}")
            raise

    def read_file_content(self, filename):
        """Read file content from backup directory and return as string"""
        try:
            file_path = self.backup_dir / filename
            if not file_path.exists():
                print(f"Error: Backup file {filename} does not exist at {file_path}")
                return None
            with open(file_path, 'r') as f:
                content = f.read()
                if not content:
                    print(f"Warning: Backup file {filename} is empty")
                else:
                    print(f"Successfully read {filename} ({len(content)} bytes)")
                return content
        except Exception as e:
            print(f"Error reading backup file {filename}: {e}")
            return None

    def send_file_content(self, filename, content):
        """Send file content to AI"""
        if not content:
            print(f"Error: No content to send for {filename}")
            return False

        print(f"\nSending {filename} to AI ({len(content)} bytes)...")
        self.file_contents[filename] = content

        # Send the complete file content with clear instructions
        content_message = f"""Here is the complete content of {filename}:

{content}

This file is part of a custom programming language implementation. I will send you all files, and then you will need to implement a new feature while preserving ALL existing functionality.

When I ask you to implement the feature, you must:
1. Keep ALL existing code exactly as is
2. Only add new code at the end of existing sections
3. Match exact code style and patterns
4. Preserve all existing functionality
5. Only add new functionality

Please confirm you have received and understood this file."""

        response = self.send_to_api(content_message)
        if response and 'candidates' in response:
            print(f"\nAI Response for {filename}:")
            print(response['candidates'][0]['content']['parts'][0]['text'])
            return True
        return False

    def normalize_line(self, line):
        """Normalize a line by removing extra whitespace"""
        return ' '.join(line.split())

    def verify_code_preservation(self, original_content, new_content):
        """Verify that the new code preserves the original structure"""
        if not original_content or not new_content:
            return False
            
        # Split content into lines and normalize
        original_lines = [self.normalize_line(line) for line in original_content.split('\n') if line.strip()]
        new_lines = [self.normalize_line(line) for line in new_content.split('\n') if line.strip()]
        
        # Check if all original lines are present in the new content
        for orig_line in original_lines:
            if orig_line not in new_lines:
                print(f"Warning: Original line missing in new content: {orig_line}")
                return False
                
        # Check if new content only adds at the end of sections
        original_sections = self.extract_sections(original_content)
        new_sections = self.extract_sections(new_content)
        
        for section_name, original_section in original_sections.items():
            if section_name in new_sections:
                new_section = new_sections[section_name]
                # Normalize sections for comparison
                orig_section_lines = [self.normalize_line(line) for line in original_section.split('\n') if line.strip()]
                new_section_lines = [self.normalize_line(line) for line in new_section.split('\n') if line.strip()]
                
                # Check if original section is preserved at the start
                for i, orig_line in enumerate(orig_section_lines):
                    if i >= len(new_section_lines) or new_section_lines[i] != orig_line:
                        print(f"Warning: Section '{section_name}' has been modified at line {i+1}")
                        print(f"Original: {orig_line}")
                        print(f"New: {new_section_lines[i] if i < len(new_section_lines) else 'missing'}")
                        return False
                    
        return True

    def extract_sections(self, content):
        """Extract sections from code content"""
        sections = {}
        current_section = None
        current_content = []
        
        for line in content.split('\n'):
            # Check for section markers
            if line.strip().startswith('typedef enum {'):
                current_section = 'enum'
                current_content = [line]
            elif line.strip().startswith('%%'):
                current_section = 'grammar'
                current_content = [line]
            elif line.strip().startswith('switch (node->type) {'):
                current_section = 'codegen'
                current_content = [line]
            elif current_section:
                current_content.append(line)
                if line.strip().startswith('}'):
                    sections[current_section] = '\n'.join(current_content)
                    current_section = None
                    current_content = []
                    
        return sections

    def generate_code_changes(self):
        """Generate code changes based on the feature request"""
        message = f"""Based on the feature request: "{self.feature_description}"

I have sent you all the original files. Now, please generate complete code for each file that needs to be modified to implement this feature.

CRITICAL REQUIREMENTS:
1. EXACT CODE PRESERVATION:
   - Keep ALL existing code exactly as is
   - Do not modify any existing functions, variables, or structures
   - Do not change any existing error handling
   - Do not change any existing line number tracking
   - Do not change any existing header includes
   - Do not change any existing token definitions
   - Do not change any existing grammar rules
   - Do not change any existing AST node structures
   - Do not change any existing code generation logic
   - Do not change any existing runtime functions

2. NEW FEATURE INTEGRATION:
   - Only add new tokens at the end of the token definitions in lexer.l
   - Only add new grammar rules at the end of the grammar section in parser.y
   - Only add new AST nodes at the end of existing enums/structures in ast.h
   - Only add new code generation cases at the end of existing switch statements in codegen.cpp
   - Only add new runtime functions at the end of runtime.c
   - Ensure new code follows exact same style and patterns

3. CODE QUALITY:
   - Match exact indentation style (4 spaces)
   - Match exact comment style (// for single line, /* */ for multi-line)
   - Match exact error message format
   - Match exact function naming conventions
   - Match exact variable naming conventions
   - Match exact header include order
   - Match exact token definition format
   - Match exact grammar rule format
   - Match exact AST node structure

Please provide the complete code for each file that needs to be modified. For each file, specify:
1. The file name
2. The complete code for the file after modifications

Format your response as:
FILE: filename
```code
// entire file content with modifications
```

IMPORTANT FORMATTING RULES:
1. DO NOT include "COMPLETE CODE:" at the start of the file content
2. DO NOT include any explanatory text in the code blocks
3. DO NOT include any markdown formatting in the code blocks
4. DO NOT include any headers or footers in the code blocks
5. Just provide the raw code content

For example, instead of:
FILE: example.c
COMPLETE CODE:
```c
// This is the code
int main() { ... }
```

Provide:
FILE: example.c
```c
int main() { ... }
```

Please provide complete code for all necessary files."""

        response = self.send_to_api(message)
        if response and 'candidates' in response:
            print("\nGenerated Code Changes:")
            print(response['candidates'][0]['content']['parts'][0]['text'])
            return response['candidates'][0]['content']['parts'][0]['text']
        return None

    def apply_code_changes(self, changes_text):
        """Apply the generated code changes to the backup files"""
        if not changes_text:
            print("No changes to apply")
            return False

        # Parse the changes text to extract file changes
        current_file = None
        current_changes = []
        changes_by_file = {}

        for line in changes_text.split('\n'):
            if line.startswith('FILE:'):
                if current_file and current_changes:
                    changes_by_file[current_file] = '\n'.join(current_changes)
                current_file = line[5:].strip()
                current_changes = []
            elif line.startswith('```code'):
                continue
            elif line.startswith('```'):
                continue
            elif current_file:
                current_changes.append(line)

        if current_file and current_changes:
            changes_by_file[current_file] = '\n'.join(current_changes)

        # Apply changes to each file in the backup directory
        for filename, changes in changes_by_file.items():
            if filename in self.source_files.values():
                try:
                    file_path = self.backup_dir / filename
                    if file_path.exists():
                        # Write the complete new content to the backup file
                        with open(file_path, 'w') as f:
                            f.write(changes)
                        print(f"Applied complete changes to backup file {filename}")
                        
                        # Verify the file was written correctly
                        with open(file_path, 'r') as f:
                            new_content = f.read()
                            if not new_content:
                                print(f"Warning: File {filename} is empty after changes")
                                return False
                    else:
                        print(f"Backup file {filename} not found")
                except Exception as e:
                    print(f"Error applying changes to backup file {filename}: {e}")
                    return False

        return True

    def send_to_api(self, message, retry_count=0):
        """Send request to Gemini API with retry logic"""
        if not self.api_key:
            print("Error: API key not set. Please run 'cookie --setup' first.")
            return None

        url = f"{self.api_endpoint}?key={self.api_key}"
        headers = {
            "Content-Type": "application/json"
        }

        data = {
            "contents": [
                {
                    "parts": [
                        {
                            "text": message
                        }
                    ]
                }
            ]
        }

        try:
            # Add a small delay before each request
            time.sleep(1)
            response = requests.post(url, headers=headers, json=data)
            
            if response.status_code == 429:  # Rate limit
                if retry_count < self.max_retries:
                    wait_time = self.retry_delay * (2 ** retry_count)
                    print(f"Rate limit hit. Waiting {wait_time} seconds before retry...")
                    time.sleep(wait_time)
                    return self.send_to_api(message, retry_count + 1)
                else:
                    print("Error: Too many requests. Please wait a few minutes and try again.")
                    return None
            
            response.raise_for_status()
            return response.json()
            
        except RequestException as e:
            if retry_count < self.max_retries:
                print(f"Error: {e}")
                print(f"Retrying in {self.retry_delay} seconds...")
                time.sleep(self.retry_delay)
                return self.send_to_api(message, retry_count + 1)
            else:
                print(f"Error: Failed after {self.max_retries} retries. Please try again later.")
                return None

    def read_original_file_content(self, filename):
        """Read file content from original source directory"""
        try:
            file_path = Path.cwd() / filename
            if not file_path.exists():
                print(f"Error: Original file {filename} does not exist at {file_path}")
                return None
            with open(file_path, 'r') as f:
                content = f.read()
                if not content:
                    print(f"Warning: Original file {filename} is empty")
                else:
                    print(f"Successfully read original {filename} ({len(content)} bytes)")
                return content
        except Exception as e:
            print(f"Error reading original file {filename}: {e}")
            return None

    def restore_backup_files(self):
        """Restore backup files with original content"""
        try:
            for file in self.source_files.values():
                original_content = self.read_original_file_content(file)
                if original_content:
                    backup_path = self.backup_dir / file
                    with open(backup_path, 'w') as f:
                        f.write(original_content)
                    print(f"Restored {file} in backup with original content")
                else:
                    print(f"Could not restore {file} - original content not found")
        except Exception as e:
            print(f"Error restoring backup files: {e}")
            return False
        return True

    def compile_backup(self):
        """Compile the backup codebase"""
        try:
            # Change to backup directory
            os.chdir(self.backup_dir)
            
            # Run compilation commands
            commands = [
                "gcc -shared -fPIC runtime.c -o libruntime.so",
                "bison -d parser.y",
                "flex lexer.l",
                "gcc -c ast.c -o ast.o",
                "gcc -c parser.tab.c -o parser.tab.o",
                "gcc -c lex.yy.c -o lex.yy.o",
                "gcc -c runtime.c -o runtime.o",
                "g++ -c codegen.cpp -o codegen.o $(llvm-config --cxxflags)",
                "g++ ast.o parser.tab.o lex.yy.o codegen.o runtime.o -o compiler $(llvm-config --ldflags --libs core)"
            ]
            
            for cmd in commands:
                print(f"\nExecuting: {cmd}")
                result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
                if result.returncode != 0:
                    print(f"Compilation error in command: {cmd}")
                    print("Error output:")
                    print(result.stderr)
                    return False, result.stderr
                print("Command successful")
            
            print("\nCompilation completed successfully!")
            return True, None
            
        except Exception as e:
            print(f"Error during compilation: {e}")
            return False, str(e)
        finally:
            # Change back to original directory
            os.chdir(Path.cwd())

    def fix_compilation_error(self, error):
        """Send compilation error to Gemini and get fixes"""
        message = f"""The code changes resulted in compilation errors. Please fix these errors while maintaining the original functionality.

Compilation Error:
{error}

Please provide complete fixed code for all necessary files. Remember to:
1. Keep ALL existing code exactly as is
2. Only add new code at the end of existing sections
3. Match exact code style and patterns
4. Preserve all existing functionality
5. Only add new functionality

Format your response as:
FILE: filename
```code
// entire file content with fixes
```

IMPORTANT FORMATTING RULES:
1. DO NOT include "COMPLETE CODE:" at the start of the file content
2. DO NOT include any explanatory text in the code blocks
3. DO NOT include any markdown formatting in the code blocks
4. DO NOT include any headers or footers in the code blocks
5. Just provide the raw code content

For example, instead of:
FILE: example.c
COMPLETE CODE:
```c
// This is the code
int main() { ... }
```

Provide:
FILE: example.c
```c
int main() { ... }
```"""

        response = self.send_to_api(message)
        if response and 'candidates' in response:
            print("\nReceived fixes from AI:")
            print(response['candidates'][0]['content']['parts'][0]['text'])
            return response['candidates'][0]['content']['parts'][0]['text']
        return None

    def implement_feature(self, feature_description):
        """Implement a new feature"""
        if not self.api_key:
            print("Error: API key not set. Please run 'cookie --setup' first.")
            return

        self.feature_description = feature_description

        # First, backup the codebase
        print(f"Backing up codebase to {self.backup_dir}")
        self.backup_codebase()

        # Restore backup files with original content
        print("\nRestoring backup files with original content...")
        if not self.restore_backup_files():
            print("Error: Failed to restore backup files with original content")
            return

        # Verify backup files exist and have content
        print("\nVerifying backup files:")
        for file in self.source_files.values():
            file_path = self.backup_dir / file
            if file_path.exists():
                with open(file_path, 'r') as f:
                    content = f.read()
                    if content:
                        print(f"✓ {file} backed up successfully ({len(content)} bytes)")
                    else:
                        print(f"✗ {file} backup is empty")
            else:
                print(f"✗ {file} backup failed")

        # Send each file from original source
        print("\nSending original files to AI...")
        for file_type, filename in self.source_files.items():
            print(f"\nSending {filename} from original source...")
            content = self.read_original_file_content(filename)
            if content:
                if self.send_file_content(filename, content):
                    print(f"Successfully sent {filename}")
                else:
                    print(f"Failed to send {filename}")
            else:
                print(f"Could not read original file {filename}")

        # Generate and apply changes until compilation succeeds
        max_attempts = 5
        attempt = 0
        
        while attempt < max_attempts:
            attempt += 1
            print(f"\nAttempt {attempt} of {max_attempts}")
            
            print("\nGenerating code changes...")
            changes = self.generate_code_changes()
            if not changes:
                print("Failed to generate code changes")
                return
                
            print("\nApplying changes to backup files...")
            if not self.apply_code_changes(changes):
                print("Failed to apply changes")
                return
                
            print("\nCompiling backup codebase...")
            success, error = self.compile_backup()
            
            if success:
                print("\nFeature implementation completed successfully!")
                return
            else:
                print("\nCompilation failed. Sending error to AI for fixes...")
                fixes = self.fix_compilation_error(error)
                if not fixes:
                    print("Failed to get fixes from AI")
                    return
                    
                print("\nApplying fixes to backup files...")
                if not self.apply_code_changes(fixes):
                    print("Failed to apply fixes")
                    return
        
        print(f"\nFailed to implement feature after {max_attempts} attempts")

def main():
    # Check if any arguments were provided
    if len(sys.argv) < 2:
        print("Usage:")
        print("  cookie --setup    # Setup API key")
        print("  cookie \"feature\"  # Implement a feature")
        sys.exit(1)

    automation = CookieAutomation()

    # Check for --setup flag
    if sys.argv[1] == "--setup":
        automation.setup()
    else:
        # Treat the argument as a feature description
        feature = sys.argv[1]
        automation.implement_feature(feature)

if __name__ == "__main__":
    main() 