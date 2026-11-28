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

    static Node search(Node root, int key) {
        if (root == null || root.data == key)
            return root;

        if (root.data > key)
            return search(root.left, key);

        return search(root.right, key);
    }

    static Node minValueNode(Node node) {
        Node current = node;
        while (current.left != null)
            current = current.left;
        return current;
    }

    static Node inOrderPredecessor(Node root, int key) {
        Node current = search(root, key);
        if (current.left != null)
            return minValueNode(current.left);

        Node pre = null;
        while (root != null) {
            if (key < root.data) {
                pre = root;
                root = root.left;
            } else if (key > root.data)
                root = root.right;
            else
                break;
        }
        return pre;
    }

    public static void main(String[] args) {
        Node root = null;
        int[] keys = {15, 10, 20, 8, 12, 16, 25};
        for (int key : keys)
            root = insert(root, key);

        Node pre = inOrderPredecessor(root, 16);
        if (pre == null)
            System.out.println("NONE");
        else
            System.out.println(pre.data);
    }
}
