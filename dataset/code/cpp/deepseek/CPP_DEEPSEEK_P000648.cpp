#include <iostream>
#include <list>

using namespace std;

class UndoRedoEditor {
private:
    list<string> history;
    list<string>::iterator current;

public:
    UndoRedoEditor() {
        history.clear();
        current = history.begin();
    }

    void type(string text) {
        history.push_back(text);
        current++;
    }

    void undo() {
        if (current != history.begin()) {
            current--;
            cout << "Undone: " << *current << endl;
        } else {
            cout << "Cannot undo" << end;
        }
    }

    void redo() {
        if (current != history.end()) {
            current++;
            cout << "Redone: " << *current << endl;
        } else {
            cout << "Cannot redo" << endl;
        }
    }

    void print() {
        for (auto it = history.begin(); it != history.end(); it++) {
            cout << *it << endl;
        }
    }
};

int main() {
    UndoRedoEditor editor;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string operation;
        cin >> operation;

        if (operation == "type") {
            string text;
            cin >> text;
            editor.type(text);
        } else if (operation == "undo") {
            editor.undo();
        } else if (operation == "redo") {
            editor.redo();
        } else if (operation == "print") {
            editor.print();
        }
    }

    return 0;
}