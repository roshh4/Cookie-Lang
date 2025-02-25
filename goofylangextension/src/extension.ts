import * as vscode from 'vscode';

let goofyHighlightsEnabled = true;

export function activate(context: vscode.ExtensionContext) {
    console.log('Lang.li extension is active!');

    // Force lines recognized as comment.line.langli to be dull gray (#666666).
    const commentRule = {
        "scope": "comment.line.langli",
        "settings": { "foreground": "#666666" }
    };

    // Apply comment rule initially
    const editorConfig = vscode.workspace.getConfiguration('editor');
    editorConfig.update('tokenColorCustomizations', {
        "textMateRules": [ commentRule ]
    }, vscode.ConfigurationTarget.Global);

    // Toggle command for Goofy highlights
    let toggleCmd = vscode.commands.registerCommand('langli.toggleGoofyHighlights', () => {
        goofyHighlightsEnabled = !goofyHighlightsEnabled;
        const config = vscode.workspace.getConfiguration('editor');

        if (!goofyHighlightsEnabled) {
            // Override everything else in source.langli to neutral color, keep comment lines dull
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
        } else {
            // Remove the override for other tokens, keep comment lines dull
            config.update('tokenColorCustomizations', {
                "textMateRules": [ commentRule ]
            }, vscode.ConfigurationTarget.Global).then(() => {
                vscode.window.showInformationMessage("Goofy highlights on");
            });
        }
    });
    context.subscriptions.push(toggleCmd);

    // Command for "Who's Dorito"
    let doritoCmd = vscode.commands.registerCommand('Goofy.dorito', () => {
        vscode.window.showInformationMessage("alpha's Dorito not ros's");
    });
    context.subscriptions.push(doritoCmd);

    // Diagnostics for missing semicolons
    let diagnosticCollection = vscode.languages.createDiagnosticCollection("langliDiagnostics");
    context.subscriptions.push(diagnosticCollection);

    if (vscode.window.activeTextEditor) {
        updateDiagnostics(vscode.window.activeTextEditor.document, diagnosticCollection);
    }
    context.subscriptions.push(
        vscode.workspace.onDidChangeTextDocument((e: vscode.TextDocumentChangeEvent) => {
            updateDiagnostics(e.document, diagnosticCollection);
        })
    );
    context.subscriptions.push(
        vscode.workspace.onDidOpenTextDocument((doc: vscode.TextDocument) => {
            updateDiagnostics(doc, diagnosticCollection);
        })
    );
}

function updateDiagnostics(document: vscode.TextDocument, collection: vscode.DiagnosticCollection) {
    if (document.languageId !== 'langli') {
        collection.clear();
        return;
    }

    const lines: string[] = document.getText().split(/\r?\n/);
    let diagnostics: vscode.Diagnostic[] = [];

    lines.forEach((line: string, i: number) => {
        const trimmed = line.trim();
        // Skip empty lines, lines that start with "//" or "comment:",
        // and lines ending with "{" or "}" => no semicolon needed
        if (
            trimmed === "" ||
            trimmed.startsWith("//") ||
            trimmed.startsWith("comment:") ||
            trimmed.endsWith("{") ||
            trimmed.endsWith("}")
        ) {
            return;
        }

        // If line doesn't end with semicolon => error
        if (!trimmed.endsWith(";")) {
            const range = new vscode.Range(i, 0, i, line.length);
            const diagnostic = new vscode.Diagnostic(
                range,
                "Missing semicolon",
                vscode.DiagnosticSeverity.Error
            );
            diagnostics.push(diagnostic);
        }
    });

    collection.set(document.uri, diagnostics);
}

export function deactivate() {}
