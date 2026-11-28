import java.util.*;

public class Main {
    static class Node {
        int value;
        Node left, right;

        Node(int value) {
            this.value = value;
            left = right = null;
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

    static int maxDiff(Node root) {
        if (root == null)
            return Integer.MIN_VALUE;

        int val = Math.max(Math.abs(root.value - max(root.left)),
                Math.abs(root.value - max(root.right)));

        return Math.max(val, Math.max(maxDiff(root.left), maxDiff(root.right)));
    }

    static int max(Node root) {
        if (root == null)
            return Integer.MIN_VALUE;
        int res = root.value;
        int left = max(root.left);
        int right = max(root.right);

        if (left > res)
            res = left;
        if (right > res)
            res = right;
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        while (n-- > 0) {
            insert(scanner.nextInt());
        }
        System.out.println(maxDiff(root));
    }
}
