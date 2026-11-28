import java.util.*;

public class Main {
    static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextInt();
        }
        Node root = buildTree(values, 0);
        countGoodNodes(root, Integer.MIN_VALUE);
        System.out.println(count);
    }

    static Node buildTree(int[] values, int i) {
        if (i >= values.length || values[i] == -1) {
            return null;
        }
        Node node = new Node(values[i]);
        node.left = buildTree(values, 2 * i + 1);
        node.right = buildTree(values, 2 * i + 2);
        return node;
   }

    static void countGoodNodes(Node node, int max) {
        if (node == null) {
            return;
        }
        if (node.val >= max) {
            count++;
            max = node.val;
        }
        countGoodNodes(node.left, max);
        countGoodNodes(node.right, max);
    }

    static class Node {
        int val;
        Node left;
        Node right;

        Node(int val) {
            this.val = val;
        }
    }
}
