import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static Node root;

    static int maxPathSum(Node node) {
        if (node == null)
            return 0;

        int left = Math.max(0, maxPathSum(node.left));
        int right = Math.max(0, maxPathSum(node.right));

        max_sum = Math.max(max_sum, left + right + node.data);

        return Math.max(left, right) + node.data;
    }

    static int max_sum = Integer.MIN_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++)
            values[i] = sc.nextInt();

        for (int i = 0; i < n; i++) {
            int left = sc.nextInt();
            int right = sc.nextInt();

            if (left != -1)
                insert(values[i], values[left - 1]);
            if (right != -1)
                insert(values[i], values[right - 1]);
        }

        maxPathSum(root);
        System.out.println(max_sum);
    }

    static void insert(int parent, int child) {
        if (root == null) {
            root = new Node(parent);
            if (child < parent)
                root.left = new Node(child);
            else
                root.right = new Node(child);
            return;
        }

        Node current = root;
        while (true) {
            if (child < current.data) {
                if (current.left == null) {
                    current.left = new Node(child);
                    break;
                } else {
                    current = current.left;
                }
            } else {
                if (current.right == null) {
                    current.right = new Node(child);
                    break;
                } else {
                    current = current.right;
                }
            }
        }
    }
}
