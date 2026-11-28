Here is the C++ solution for your problem:

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class TextEditor {
public:
    list<char> text;
    list<char>::iterator cursor;

    TextEditor() {
        cursor = text.end();
    }

    void addText(string s) {
        text.insert(cursor, s.begin(), s.end());
    }

    void deleteText(int k) {
        for(int i = 0; i < k && cursor != text.begin(); i++) {
            cursor--;
        }
        text.erase(cursor, cursor);
    }

    string cursorLeft(int k) {
        cursor = cursor;
        if(k > text.size()) {
            k = text.size();
        }
        for(int i = 0; i < k; i++) {
            if(cursor != text.begin()) {
                cursor--;
            }
        }
        string res;
        for(auto it = max(text.begin(), cursor); it != min(cursor, text.end()); it++) {
            res += *it;
        }
        return res;
    }

    string cursorRight(int k) {
        cursor = cursor;
        if(k > text.size()) {
            k = text.size();
        }
        for(int i = 0; i < k; i++) {
            if(cursor != text.end()) {
                cursor++;
            }
        }
        string res;
        for(auto it = max(text.begin(), cursor); it != min(cursor, text.end()); it++) {
            res += *it;
        }
        return res;
    }
};

int main() {
    int q;
    cin >> q;
    TextEditor editor;
    for(int i = 0; i < q; i++) {
        string op;
        cin >> op;
        if(op == "addText") {
            string s;
            cin >> s;
            editor.addText(s);
        } else if(op == "deleteText") {
            int k;
            cin >> k;
            editor.deleteText(k);
        } else if(op == "cursorLeft") {
            int k;
            cin >> k;
            cout << editor.cursorLeft(k) << endl;
        } else if(op == "cursorRight") {
            int k;
            cin >> k;
            cout << editor.cursorRight(k) << endl;
        }
    }
    return 0;
}

This code uses a linked list data structure to implement the operations. The cursor is a list iterator pointing to the position of the insertion point. The operations are added to the list in such a way that the cursor moves. The operations are then processed and the results are printed.