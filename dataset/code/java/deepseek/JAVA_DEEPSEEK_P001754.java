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

    static void inorder(Node node, int level, Res res) {
        if (node == null)
            return;
        inorder(node.left, level + 1, res);
        if (res.max_level < level) {
            res.res = node.data;
            res.max_level = level;
        }
        inorder(node.right, level + 1, res);
    }

    static void findLeftMost(Node node) {
        Res res = new Res();
        inorder(node, 1, res);
        System.out.println(res.res);
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        findLeftMost(root);
    }

    static class Res {
        int max_level = -1;
        int res = -1;
    }
}
