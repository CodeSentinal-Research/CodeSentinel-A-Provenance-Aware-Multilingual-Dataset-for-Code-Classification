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

    static Node removeLeafNodes(Node root) {
        if (root == null)
            return null;
        if (root.left == null && root.right == null) {
            System.out.print(root.data + " ");
            return null;
        }
        root.left = removeLeafNodes(root.left);
        root.right = removeLeafNodes(root.right);
        return root;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        root = null;
        while (n-- > 0) {
            int val = sc.nextInt();
            root = insert(root, val);
        }
        while (root != null) {
            root = removeLeafNodes(root);
            System.out.println();
        }
    }
}
