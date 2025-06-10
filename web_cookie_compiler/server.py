from http.server import HTTPServer, SimpleHTTPRequestHandler
import json
import os
import subprocess
import tempfile

class CompilerHandler(SimpleHTTPRequestHandler):
    def do_POST(self):
        if self.path == '/compile':
            content_length = int(self.headers['Content-Length'])
            post_data = self.rfile.read(content_length)
            data = json.loads(post_data.decode('utf-8'))
            code = data['code']

            # Create a temporary directory for compilation
            with tempfile.TemporaryDirectory() as temp_dir:
                # Write the C code to a file
                c_file = os.path.join(temp_dir, 'hello.c')
                with open(c_file, 'w') as f:
                    f.write(code)

                # Compile the code
                try:
                    subprocess.run([
                        'emcc',
                        '-o', 'hello.js',
                        c_file,
                        '-s', 'WASM=1',
                        '-s', 'EXPORTED_FUNCTIONS=["_main"]',
                        '-s', 'ENVIRONMENT=web',
                        '-s', 'MODULARIZE=1',
                        '-s', 'EXPORT_NAME="HelloModule"',
                        '-s', 'EXPORT_ES6=1',
                        '-s', 'USE_ES6_IMPORT_META=1',
                        '-s', 'EXPORTED_RUNTIME_METHODS=["ccall", "cwrap"]',
                        '-s', 'NO_EXIT_RUNTIME=1',
                        '-O3'
                    ], cwd=temp_dir, check=True)

                    # Copy the compiled files to the public directory
                    os.makedirs('public', exist_ok=True)
                    subprocess.run(['cp', os.path.join(temp_dir, 'hello.js'), 'public/'])
                    subprocess.run(['cp', os.path.join(temp_dir, 'hello.wasm'), 'public/'])

                    self.send_response(200)
                    self.send_header('Content-type', 'application/json')
                    self.end_headers()
                    self.wfile.write(json.dumps({'status': 'success'}).encode())
                except subprocess.CalledProcessError as e:
                    self.send_response(500)
                    self.send_header('Content-type', 'application/json')
                    self.end_headers()
                    self.wfile.write(json.dumps({'status': 'error', 'message': str(e)}).encode())
        else:
            return SimpleHTTPRequestHandler.do_POST(self)

    def do_GET(self):
        return SimpleHTTPRequestHandler.do_GET(self)

if __name__ == '__main__':
    server_address = ('', 8000)
    httpd = HTTPServer(server_address, CompilerHandler)
    print('Server running on port 8000...')
    httpd.serve_forever() 