import java.util.Scanner;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static class Tree {
        Node root;

        Node buildTree(String[] arr, int i, int n) {
            if (i == n) return null;
            Node t = new Node(Integer.parseInt(arr[i]));
            t.left = buildTree(arr, 2 * i + 1, n);
            t.right = buildTree(arr, 2 * i + 2, n);
            return t;
        }

        int diameter(Node root) {
            if (root == null) return 0;
            int lheight = height(root.left);
            int rheight = height(root.right);
            return Math.max(lheight + rheight + 1, Math.max(diameter(root.left), diameter(root.right)));
        }

        int height(Node root) {
            if (root == null) return 0;
            return 1 + Math.max(height(root.left), height(root.right));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Tree tree = new Tree();
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) arr[i] = scanner.next();
        tree.root = tree.buildTree(arr, 0, n);
        System.out.println(tree.diameter(tree.root));
    }
}
