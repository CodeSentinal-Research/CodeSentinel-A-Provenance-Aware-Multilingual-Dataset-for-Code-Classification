import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    static Node newNode(int data) {
        Node Node = new Node(data);
        return (Node);
    }

    static Node removeSingleParentNodes(Node root) {
        if (root == null)
            return null;

        root.left = removeSingleParentNodes(root.left);
        root.right = removeSingleParentNodes(root.right);

        if (root.left == null && root.right != null)
            return root.right;
        if (root.left != null && root.right == null)
            return root.left;

        return root;
    }

    static void inOrder(Node root) {
        if (root != null) {
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
    }

    public static void main(String[] args) {
        Node root = newNode(15);
        root.left = newNode(10);
        root.right = newNode(20);
        root.left.left = newNode(8);
        root.left.right = newNode(12);
        root.right.left = newNode(16);
        root.right.right = newNode(25);

        root = removeSingleParentNodes(root);

        inOrder(root);
    }
}
