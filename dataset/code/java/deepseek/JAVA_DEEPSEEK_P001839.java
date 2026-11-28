import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    boolean findPairUtil(Node node, int sum, HashSet<Integer> set) {
        if (node == null) {
            return false;
        }

        if (findPairUtil(node.left, sum, set)) {
            return true;
        }

        if (set.contains(sum - node.data)) {
            return true;
        }

        set.add(node.data);

        return findPairUtil(node.right, sum, set);
    }

    boolean findPair(Node node, int sum) {
        HashSet<Integer> set = new HashSet<Integer>();
        return findPairUtil(node, sum, set);
    }

    Node insert(Node node, int data) {
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
}

public class Main {
    public static void main (String[] args) {
        BinaryTree tree = new BinaryTree();
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            tree.root = tree.insert(tree.root, data);
        }
        int sum = scanner.nextInt();
        if (tree.findPair(tree.root, sum)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
