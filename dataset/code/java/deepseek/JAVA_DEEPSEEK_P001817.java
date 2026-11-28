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

    static Node ceil(Node root, int key) {
        if (root == null) {
            return null;
        }

        Node res = null;

        while (root != null) {
            if (root.data == key) {
                return root;
            }

            if (root.data < key) {
                root = root.right;
            } else {
                res = root;
                root = root.left;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            int val = sc.nextInt();
            root = insert(root, val);
        }
        int key = sc.nextInt();
        Node ceil = ceil(root, key);
        if (ceil == null) {
            System.out.println("NONE");
        } else {
            System.out.println(ceil.data);
        }
    }
}
