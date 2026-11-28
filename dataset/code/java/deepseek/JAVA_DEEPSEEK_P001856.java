import java.util.Scanner;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node() {}
    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
}

public class Main {
    Node first = null;
    Node last = null;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            root = insertIntoBST(root, val);
        }
        scanner.close();
        Main main = new Main();
        main.flatten(root);
        main.printList(main.first);
    }

    public void flatten(Node root) {
        if (root == null) return;
        flatten(root.left);
        if (last != null) {
            last.right = root;
            root.left = last;
        } else {
            first = root;
        }
        last = root;
        Node right = root.right;
        root.right = null;
        flatten(right);
    }

    public void printList(Node node) {
        while (node != null) {
            System.out.println(node.val);
            node = node.right;
        }
    }

    public static Node insertIntoBST(Node root, int val) {
        if (root == null) {
            return new Node(val, null, null);
        }
        if (val < root.val) {
            root.left = insertIntoBST(root.left, val);
        } else if (val > root.val) {
            root.right = insertIntoBST(root.right, val);
        }
        return root;
    }
}
