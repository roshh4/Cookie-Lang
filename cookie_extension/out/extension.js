"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.activate = activate;
exports.deactivate = deactivate;
const vscode = require("vscode");
let goofyHighlightsEnabled = true;
function activate(context) {
    console.log('Cookie extension is active!');
    // Define comment rules: ensure comment lines are always dull gray (#666666)
    const commentRule = {
        "sc`ope": "comment.line.cookie",
        "settings": { "foreground": "#666666" }
    };
    const punctuationCommentRule = {
        "scope": "punctuation.definition.comment.cookie",
        "settings": { "foreground": "#666666" }
    };
    const commentRules = [commentRule, punctuationCommentRule];
    // Apply comment rules initially
    const editorConfig = vscode.workspace.getConfiguration('editor');
    editorConfig.update('tokenColorCustomizations', {
        "textMateRules": commentRules
    }, vscode.ConfigurationTarget.Global);
    // Toggle command for Goofy highlights
    let toggleCmd = vscode.commands.registerCommand('cookie.toggleGoofyHighlights', () => {
        goofyHighlightsEnabled = !goofyHighlightsEnabled;
        const config = vscode.workspace.getConfiguration('editor');
        if (!goofyHighlightsEnabled) {
            // Override all tokens in source.cookie to black (#000000), preserving comment colors
            config.update('tokenColorCustomizations', {
                "textMateRules": [
                    {
                        "scope": "source.cookie",
                        "settings": { "foreground": "#000000" }
                    },
                    ...commentRules
                ]
            }, vscode.ConfigurationTarget.Global).then(() => {
                vscode.window.showInformationMessage("Goofy highlights off (reload window if not visible)");
            });
        }
        else {
            // Restore highlighting by removing override (keep comment rules)
            config.update('tokenColorCustomizations', {
                "textMateRules": commentRules
            }, vscode.ConfigurationTarget.Global).then(() => {
                vscode.window.showInformationMessage("Goofy highlights on (reload window if not visible)");
            });
        }
    });
    context.subscriptions.push(toggleCmd);
    // Command: "Who's Dorito" displays "alpha's Dorito not ros's"
    let doritoCmd = vscode.commands.registerCommand('Goofy.dorito', () => {
        vscode.window.showInformationMessage("alpha's Dorito not ros's");
    });
    context.subscriptions.push(doritoCmd);
    // Diagnostics: Simple check for missing semicolons
    let diagnosticCollection = vscode.languages.createDiagnosticCollection("cookieDiagnostics");
    context.subscriptions.push(diagnosticCollection);
    if (vscode.window.activeTextEditor) {
        updateDiagnostics(vscode.window.activeTextEditor.document, diagnosticCollection);
    }
    context.subscriptions.push(vscode.workspace.onDidChangeTextDocument((e) => {
        updateDiagnostics(e.document, diagnosticCollection);
    }));
    context.subscriptions.push(vscode.workspace.onDidOpenTextDocument((doc) => {
        updateDiagnostics(doc, diagnosticCollection);
    }));
    // Auto-completion (IntelliSense) provider for Cookie language
    let completionProvider = vscode.languages.registerCompletionItemProvider('cookie', {
        provideCompletionItems(document, position) {
            let completions = [];
            // Keywords
            const keywords = ['if', 'else', 'while', 'until', 'loop', 'switch', 'case:', 'default', 'break', 'return', 'fun'];
            for (const kw of keywords) {
                let item = new vscode.CompletionItem(kw, vscode.CompletionItemKind.Keyword);
                item.detail = "Keyword";
                completions.push(item);
            }
            // Types
            const types = ['int', 'float', 'bool', 'char', 'str', 'var', 'type', 'inline'];
            for (const t of types) {
                let item = new vscode.CompletionItem(t, vscode.CompletionItemKind.TypeParameter);
                item.detail = "Type";
                completions.push(item);
            }
            // Built-in functions
            const builtins = ['print', 'input'];
            for (const func of builtins) {
                let item = new vscode.CompletionItem(func, vscode.CompletionItemKind.Function);
                item.detail = "Built-in function";
                item.insertText = new vscode.SnippetString(func + "($1);");
                completions.push(item);
            }
            return completions;
        }
    }, '.' // Trigger character; you can adjust as needed.
    );
    context.subscriptions.push(completionProvider);
}
function updateDiagnostics(document, collection) {
    if (document.languageId !== 'cookie') {
        collection.clear();
        return;
    }
    const lines = document.getText().split(/\r?\n/);
    let diagnostics = [];
    lines.forEach((line, i) => {
        const trimmed = line.trim();
        // Skip empty lines, lines starting with "//" or "comment:" (as defined in the grammar), and lines ending with "{" or "}"
        if (trimmed === "" ||
            trimmed.startsWith("//") ||
            trimmed.startsWith("comment:") ||
            trimmed.endsWith("{") ||
            trimmed.endsWith("}")) {
            return;
        }
        if (!trimmed.endsWith(";")) {
            const range = new vscode.Range(i, 0, i, line.length);
            const diagnostic = new vscode.Diagnostic(range, "Missing semicolon", vscode.DiagnosticSeverity.Error);
            diagnostics.push(diagnostic);
        }
    });
    collection.set(document.uri, diagnostics);
}
function deactivate() { }
//# sourceMappingURL=extension.js.map