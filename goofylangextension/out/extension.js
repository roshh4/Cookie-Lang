"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.activate = activate;
exports.deactivate = deactivate;
const vscode = require("vscode");
let goofyHighlightsEnabled = true;
function activate(context) {
    console.log('Lang.li extension is active!');
    // Always force lines recognized as comment.line.langli to be a dull color (#666666).
    const commentRule = {
        "scope": "comment.line.langli",
        "settings": { "foreground": "#666666" }
    };
    const editorConfig = vscode.workspace.getConfiguration('editor');
    editorConfig.update('tokenColorCustomizations', {
        "textMateRules": [commentRule]
    }, vscode.ConfigurationTarget.Global);
    // Toggle command for Goofy highlights
    let toggleCmd = vscode.commands.registerCommand('langli.toggleGoofyHighlights', () => {
        goofyHighlightsEnabled = !goofyHighlightsEnabled;
        const config = vscode.workspace.getConfiguration('editor');
        if (!goofyHighlightsEnabled) {
            // Override everything else in source.langli to neutral color, but keep comment lines dull.
            config.update('tokenColorCustomizations', {
                "textMateRules": [
                    {
                        "scope": "source.langli",
                        "settings": { "foreground": "#888888" }
                    },
                    commentRule
                ]
            }, vscode.ConfigurationTarget.Global).then(() => {
                vscode.window.showInformationMessage("Goofy highlights off");
            });
        }
        else {
            // Remove the override for other tokens; keep comment lines dull.
            config.update('tokenColorCustomizations', {
                "textMateRules": [commentRule]
            }, vscode.ConfigurationTarget.Global).then(() => {
                vscode.window.showInformationMessage("Goofy highlights on");
            });
        }
    });
    context.subscriptions.push(toggleCmd);
    // Command for "Who's Dorito"
    let doritoCmd = vscode.commands.registerCommand('Goofy.dorito', () => {
        // Show the message "alpha's Dorito not ros's"
        vscode.window.showInformationMessage("alpha's Dorito not ros's");
    });
    context.subscriptions.push(doritoCmd);
    // Diagnostics for missing semicolons
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
    let diagnostics = [];
    const lines = document.getText().split(/\r?\n/);
    lines.forEach((line, i) => {
        const trimmed = line.trim();
        // Skip empty lines, lines starting with "//", lines starting with "comment:",
        // and lines ending with "{" or "}" so they don't require semicolons.
        if (trimmed === "" ||
            trimmed.startsWith("//") ||
            trimmed.startsWith("comment:") ||
            trimmed.endsWith("{") ||
            trimmed.endsWith("}")) {
            return;
        }
        // If line doesn't end with semicolon, create a diagnostic.
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