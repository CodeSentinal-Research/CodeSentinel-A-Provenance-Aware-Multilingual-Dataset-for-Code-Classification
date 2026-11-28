import java.io.*;
import java.util.*;

public class Main {
    static class TextEditor {
        Stack<String> undoStack = new Stack<>();
        Stack<String> redoStack = new Stack<>();
        StringBuilder current = new StringBuilder();

        public void type(String text) {
            undoStack.push(current.toString());
            current.append(text);
            redoStack.clear();
        }

        public void undo() {
            if (!undoStack.isEmpty()) {
                redoStack.push(current.toString());
                current = new StringBuilder(undoStack.pop());
            }
        }

        public void redo() {
            if (!redoStack.isEmpty()) {
                undoStack.push(current.toString());
                current = new StringBuilder(redoStack.pop());
            }
        }

        public void print() {
            System.out.println(current);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        TextEditor editor = new TextEditor();
        while (q-- > 0) {
            String[] op = br.readLine().split(" ");
            switch (op[0]) {
                case "type":
                    editor.type(op[1]);
                    break;
                case "undo":
                    editor.undo();
                    break;
                case "redo":
                    editor.redo();
                    break;
                case "print":
                    editor.print();
                    break;
            }
        }
    }
}
