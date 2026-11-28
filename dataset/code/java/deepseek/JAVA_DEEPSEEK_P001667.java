import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
        }
        scanner.close();

        Tree tree = new Tree(values);
        System.out.println(tree.maxAncestorDifference());
    }
}

class Tree {
    private Node root;

    public Tree(int[] values) {
        this.root = buildTree(values, 0, values.length - 1);
    }

    private Node buildTree(int[] values, int start, int end) {
        if (start > end) {
            return null;
        }
        int mid = (start + end) / 2;
        Node node = new Node(values[mid]);
        node.left = buildTree(values, start, mid - 1);
        node.right = buildTree(values, mid + 1, end);
        return node;
    }

    public int maxAncestorDifference() {
        return maxAncestorDifference(root, root.value, root.value);
    }

    private int maxAncestorDifference(Node node, int min, int max) {
        if (node == null) {
            return max - min;
        }
        max = Math.max(max, node.value);
        min = Math.min(min, node.value);
        return Math.max(maxAncestorDifference(node.left, min, max), maxAncestorDifference(node.right, min, max));
    }
}

class Node {
    int value;
    Node left, right;

    public Node(int value) {
        this.value = value;
    }
}
