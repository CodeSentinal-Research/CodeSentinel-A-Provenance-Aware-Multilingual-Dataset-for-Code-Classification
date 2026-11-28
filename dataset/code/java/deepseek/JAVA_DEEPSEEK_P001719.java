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

    static ArrayList<Integer> longestPath(Node root) {
        if (root == null) {
            return new ArrayList<>();
        }

        ArrayList<Integer> left = longestPath(root.left);
        ArrayList<Integer> right = longestPath(root.right);

        if (left.size() > right.size()) {
            left.add(root.data);
            return left;
        } else {
            right.add(root.data);
            return right;
        }
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        ArrayList<Integer> result = longestPath(root);
        for (int i = result.size() - 1; i >= 0; i--) {
            System.out.print(result.get(i) + " ");
        }
    }
}
