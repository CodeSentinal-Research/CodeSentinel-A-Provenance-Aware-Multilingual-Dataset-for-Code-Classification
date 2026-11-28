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

    static void inorder(Node node, ArrayList<Integer> arr) {
        if (node == null)
            return;

        inorder(node.left, arr);
        arr.add(node.data);
        inorder(node.right, arr);
    }

    static int maxDiff(Node node) {
        ArrayList<Integer> arr = new ArrayList<>();
        inorder(node, arr);

        int diff = Integer.MIN_VALUE;
        for (int i = 0; i < arr.size() - 1; i++) {
            diff = Math.max(diff, Math.abs(arr.get(i) - arr.get(i + 1)));
        }
        return diff;
    }

    public static void main(String[] args) {
        root = new Node(8);
        root.left = new Node(3);
        root.right = new Node(10);
        root.left.left = new Node(1);
        root.left.right = new Node(6);
        root.right.right = new Node(14);
        root.right.right.left = new Node(13);

        System.out.println(maxDiff(root));
    }
}
