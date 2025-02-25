"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.activate = activate;
exports.deactivate = deactivate;
const vscode = require("vscode");
let goofyHighlightsEnabled = true;
function activate(context) {
    console.log('Lang.li extension is active!');
    // Define rules to force comments (and the comment punctuation) to dull gray.
    const commentRules = [
        {
            "scope": "comment.line.langli",
            "settings": { "foreground": "#666666" }
        },
        {
            "scope": "punctuation.definition.comment.langli",
            "settings": { "foreground": "#666666" }
        }
    ];
    // Apply comment rules initially.
    const editorConfig = vscode.workspace.getConfiguration('editor');
    editorConfig.update('tokenColorCustomizations', {
        "textMateRules": commentRules
    }, vscode.ConfigurationTarget.Global);
    // Toggle command for Goofy highlights.
    let toggleCmd = vscode.commands.registerCommand('langli.toggleGoofyHighlights', () => {
        goofyHighlightsEnabled = !goofyHighlightsEnabled;
        const config = vscode.workspace.getConfiguration('editor');
        if (!goofyHighlightsEnabled) {
            // Override all tokens in source.langli to neutral color while preserving comment colors.
            config.update('tokenColorCustomizations', {
                "textMateRules": [
                    {
                        "scope": "source.langli",
                        "settings": { "foreground": "#888888" }
                    },
                    ...commentRules
                ]
            }, vscode.ConfigurationTarget.Global).then(() => {
                vscode.window.showInformationMessage("Goofy highlights off");
            });
        }
        else {
            // Restore normal highlighting except for comments.
            config.update('tokenColorCustomizations', {
                "textMateRules": commentRules
            }, vscode.ConfigurationTarget.Global).then(() => {
                vscode.window.showInformationMessage("Goofy highlights on");
            });
        }
    });
    context.subscriptions.push(toggleCmd);
    // Command for "Who's Dorito" that displays "alpha's Dorito not ros's"
    let doritoCmd = vscode.commands.registerCommand('Goofy.dorito', () => {
        vscode.window.showInformationMessage("alpha's Dorito not ros's");
    });
    context.subscriptions.push(doritoCmd);
    // Simple diagnostics: Check for missing semicolons.
    let diagnosticCollection = vscode.languages.createDiagnosticCollection("langliDiagnostics");
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
}
function updateDiagnostics(document, collection) {
    if (document.languageId !== 'langli') {
        collection.clear();
        return;
    }
    const lines = document.getText().split(/\r?\n/);
    let diagnostics = [];
    lines.forEach((line, i) => {
        const trimmed = line.trim();
        // Skip empty lines, lines starting with "//" or "comment:", and block delimiters.
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