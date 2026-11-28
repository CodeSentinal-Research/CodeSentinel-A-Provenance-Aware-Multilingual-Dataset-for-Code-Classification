import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine().trim());
        TextEditor textEditor = new TextEditor();
        for (int i = 0; i < q; i++) {
            String[] operation = br.readLine().split(" ");
            switch (operation[0]) {
                case "addText":
                    textEditor.addText(operation[1]);
                    break;
                case "deleteText":
                    textEditor.deleteText(Integer.parseInt(operation[1]));
                    break;
                case "cursorLeft":
                    System.out.println(textEditor.cursorLeft(Integer.parseInt(operation[1])));
                    break;
                case "cursorRight":
                    System.out.println(textEditor.cursorRight(Integer.parseInt(operation[1])));
                    break;
            }
        }
    }
}

class TextEditor {
    private Node cursor;

    public TextEditor() {
        cursor = new Node("");
    }

    public void addText(String text) {
        Node newNode = new Node(text);
        newNode.next = cursor.next;
        cursor.next = newNode;
    }

    public void deleteText(int k) {
        Node temp = cursor;
        while (temp.next != null && k-- > 0) {
            temp.next = temp.next.next;
        }
    }

    public String cursorLeft(int k) {
        while (cursor.prev != null && k-- > 0) {
            cursor = cursor.prev;
        }
        return getLast10Chars();
    }

    public String cursorRight(int k) {
        while (cursor.next != null && k-- > 0) {
            cursor = cursor.next;
        }
        return getLast10Chars();
    }

    private String getLast10Chars() {
        StringBuilder sb = new StringBuilder();
        Node temp = cursor;
        for (int i = 0; i < 10 && temp != null; i++, temp = temp.prev) {
            sb.append(temp.val);
        }
        return sb.reverse().toString();
    }

    class Node {
        String val;
        Node prev;
        Node next;

        Node(String val) {
            this.val = val;
        }
    }
}
