import java.io.*;
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

    static Node insert(Node node, int data) {
        if (node == null) {
            return (new Node(data));
        } else {
            if (data <= node.data) {
                node.left = insert(node.left, data);
            } else {
                node.right = insert(node.right, data);
            }
            return node;
        }
    }

    static boolean findPairUtil(Node node, int sum, HashSet<Integer> set) {
        if (node == null) {
            return false;
        }

        if (findPairUtil(node.left, sum, set)) {
            return true;
        }

        if (set.contains(sum - node.data)) {
            System.out.println("Pair is (" + (sum - node.data) + ", " + node.data + ")");
            return true;
        } else {
            set.add(node.data);
        }

        return findPairUtil(node.right, sum, set);
    }

    static void findPair(Node node, int sum) {
        HashSet<Integer> set = new HashSet<Integer>();
        if (!findPairUtil(node, sum, set)) {
            System.out.print("Pairs do not exist");
        }
    }

    public static void main(String[] args) {
        Node root1 = null;
        Node root2 = null;
        int sum;

        try (Scanner scanner = new Scanner(System.in)) {
            int n1 = scanner.nextInt();
            for (int i = 0; i < n1; i++) {
                root1 = insert(root1, scanner.nextInt());
            }

            int n2 = scanner.nextInt();
            for (int i = 0; i < n2; i++) {
                root2 = insert(root2, scanner.nextInt());
            }

            sum = scanner.nextInt();
        }

        findPair(root1, sum);
        findPair(root2, sum);
    }
}
