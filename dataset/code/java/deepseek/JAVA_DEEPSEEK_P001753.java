import java.util.Scanner;

public class Main {
    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
            left = null;
            right = null;
        }
    }

    static Node root;

    static void insert(int value) {
        root = insertRec(root, value);
    }

    static Node insertRec(Node root, int value) {
        if (root == null) {
            root = new Node(value);
            return root;
        }

        if (value < root.value)
            root.left = insertRec(root.left, value);
        else if (value > root.value)
            root.right = insertRec(root.right, value);

        return root;
    }

    static int findLeftMostNode(Node root) {
        if (root == null || (root.left == null && root.right == null))
            return -1;

        return root.value;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        while (n-- > 0) {
            int value = scanner.nextInt();
            insert(value);
        }

        System.out.println(findLeftMostNode(root));
    }
}
