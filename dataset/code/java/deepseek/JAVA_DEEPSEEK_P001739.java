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

    static Node removeLeafNodes(Node node) {
        if (node == null)
            return null;

        if (node.left == null && node.right == null)
            return null;

        node.left = removeLeafNodes(node.left);
        node.right = removeLeafNodes(node.right);

        return node;
    }

    static void inOrder(Node node) {
        if (node == null)
            return;

        inOrder(node.left);
        System.out.print(node.data + " ");
        inOrder(node.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        root = new Node(1);
        removeLeafNodes(root);
        inOrder(root);
    }
}
