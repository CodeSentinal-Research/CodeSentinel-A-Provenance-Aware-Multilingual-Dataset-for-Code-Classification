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

    static void diagonalSumUtil(Node root, int diagonal, Map<Integer, Integer> sum) {
        if (root == null)
            return;

        sum.put(diagonal, sum.getOrDefault(diagonal, 0) + root.data);
        diagonalSumUtil(root.left, diagonal + 1, sum);
        diagonalSumUtil(root.right, diagonal, sum);
    }

    static void diagonalSum(Node root) {
        Map<Integer, Integer> sum = new HashMap<>();
        diagonalSumUtil(root, 0, sum);

        for (int s : sum.values()) {
            System.out.println(s);
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

        diagonalSum(root);
    }
}
