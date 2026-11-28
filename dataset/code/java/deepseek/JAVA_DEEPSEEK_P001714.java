import java.util.Scanner;

public class Main {
    static class Node {
        int data;
        Node left, right;
        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static int count = 0;

    static void countHalfNodes(Node root) {
        if (root != null) {
            if (root.left == null ^ root.right == null) {
                count++;
            }
            countHalfNodes(root.left);
            countHalfNodes(root.right);
       }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int data = sc.nextInt();
            root = insert(root, data);
        }
        countHalfNodes(root);
        System.out.println(count);
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
}
