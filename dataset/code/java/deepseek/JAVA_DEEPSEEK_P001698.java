import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static Node root;

    static void deleteLeavesWithValue(Node node, int x) {
        if (node == null) {
            return;
        }
        if (node.left != null) {
            if (node.left.left == null && node.left.right == null && node.left.val == x) {
                node.left = null;
            }
        }
        if (node.right != null) {
            if (node.right.left == null && node.right.right == null && node.right.val == x) {
                node.right = null;
            }
        }
        deleteLeavesWithValue(node.left, x);
        deleteLeavesWithValue(node.right, x);
    }

    static void inOrder(Node node) {
        if (node == null) {
            return;
        }
        inOrder(node.left);
        System.out.print(node.val + " ");
        inOrder(node.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nodes = new int[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = sc.nextInt();
        }
        root = new Node(nodes[0]);
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        for (int i = 1; i < n; i += 2) {
            Node parent = queue.poll();
            if (nodes[i] != -1) {
                parent.left = new Node(nodes[i]);
                queue.add(parent.left);
            }
            if (nodes[i + 1] != -1) {
                parent.right = new Node(nodes[i + 1]);
                queue.add(parent.right);
            }
        }
        int x = sc.nextInt();
        deleteLeavesWithValue(root, x);
        inOrder(root);
    }
}
