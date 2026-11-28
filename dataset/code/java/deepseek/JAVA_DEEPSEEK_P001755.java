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

    static void inorder(Node node, int level, MaxLevel max_level) {
        if (node == null) return;

        inorder(node.left, level + 1, max_level);

        if (max_level.maxLevel < level) {
            max_level.maxLevel = level;
            max_level.node = node;
        }

        inorder(node.right, level + 1, max_level);
    }

    static void printRightmost(Node node) {
        MaxLevel max = new MaxLevel();
        inorder(node, 1, max);
        System.out.println(max.node.data);
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.right = new Node(6);
        root.left.left.left = new Node(7);
        root.left.left.right = new Node(8);
        root.left.right.left = new Node(9);
        root.left.right.right = new Node(10);
        root.right.right.left = new Node(11);
        root.right.right.right = new Node(12);
        printRightmost(root);
    }

    static class MaxLevel {
        int maxLevel = -1;
        Node node = null;
    }
}
