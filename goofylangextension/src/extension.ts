import * as vscode from 'vscode';

let goofyHighlightsEnabled = true;

export function activate(context: vscode.ExtensionContext) {
    console.log('Lang.li extension is active!');

    // Toggle command for Goofy highlights
    let toggleCmd = vscode.commands.registerCommand('langli.toggleGoofyHighlights', () => {
        goofyHighlightsEnabled = !goofyHighlightsEnabled;
        const config = vscode.workspace.getConfiguration('editor');
        if (!goofyHighlightsEnabled) {
            config.update('tokenColorCustomizations', {
                "textMateRules": [
                    {
                        "scope": "source.langli",
                        "settings": { "foreground": "#888888" }
                    }
                ]
            }, vscode.ConfigurationTarget.Global).then(() => {
                vscode.window.showInformationMessage("Goofy highlights off");
            });
        } else {
            config.update('tokenColorCustomizations', {}, vscode.ConfigurationTarget.Global)
            .then(() => {
                vscode.window.showInformationMessage("Goofy highlights on");
            });
        }
    });
    context.subscriptions.push(toggleCmd);

    // Command for "Goofy.dorito"
    let doritoCmd = vscode.commands.registerCommand('Goofy.dorito', () => {
        vscode.window.showInformationMessage("alpha's Dorito not ros's");
    });
    context.subscriptions.push(doritoCmd);

    // Simple diagnostics: Check for missing semicolons
    let diagnosticCollection = vscode.languages.createDiagnosticCollection("langliDiagnostics");
    context.subscriptions.push(diagnosticCollection);

    if (vscode.window.activeTextEditor) {
        updateDiagnostics(vscode.window.activeTextEditor.document, diagnosticCollection);
    }
    context.subscriptions.push(
        vscode.workspace.onDidChangeTextDocument(e => updateDiagnostics(e.document, diagnosticCollection))
    );
    context.subscriptions.push(
        vscode.workspace.onDidOpenTextDocument(doc => updateDiagnostics(doc, diagnosticCollection))
    );
}

function updateDiagnostics(document: vscode.TextDocument, collection: vscode.DiagnosticCollection) {
    if (document.languageId !== 'langli') {
        collection.clear();
        return;
    }

    let diagnostics: vscode.Diagnostic[] = [];
    const lines = document.getText().split(/\r?\n/);

    // Simple rule: every non-empty, non-comment, non-block line should end with a semicolon.
    lines.forEach((line, i) => {
        const trimmed = line.trim();
        if (trimmed === "" || trimmed.startsWith("//") || trimmed.endsWith("{") || trimmed.endsWith("}")) {
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

export function deactivate() {}
