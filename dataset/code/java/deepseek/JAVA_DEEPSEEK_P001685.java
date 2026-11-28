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

    static Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        } else {
            Node cur;
            if (data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
           }
            return root;
        }
    }

    static Node findNode(Node root, int key) {
        while (root != null) {
            if (key < root.data)
                root = root.left;
            else if (key > root.data)
                root = root.right;
            else
                return root;
        }
        return null;
    }

    static Node findMin(Node root) {
        if (root.left == null)
            return root;
        return findMin(root.left);
    }

    static Node inOrderSuccessor(Node root, int key) {
        Node current = findNode(root, key);
        if (current == null)
            return null;
        if (current.right != null) {
            return findMin(current.right);
        } else {
            Node successor = null;
            Node ancestor = root;
            while (ancestor != current) {
                if (current.data < ancestor.data) {
                    successor = ancestor;
                    ancestor = ancestor.left;
                } else {
                    ancestor = ancestor.right;
                }
            }
            return successor;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        while (n-- > 0) {
            int data = scanner.nextInt();
            root = insert(root, data);
        }
        int key = scanner.nextInt();
        Node successor = inOrderSuccessor(root, key);
        if (successor == null)
            System.out.println("NONE");
        else
            System.out.println(successor.data);
    }
}
