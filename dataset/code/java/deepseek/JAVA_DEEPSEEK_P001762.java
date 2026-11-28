import java.io.*;
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
    static int minSum = Integer.MAX_VALUE;
    static Node minNode;

    static void inorder(Node node, int n) {
        if (node == null)
            return;
        inorder(node.left, n);
        if (node.data < minSum) {
            minSum = node.data;
            minNode = node;
        }
        inorder(node.right, n);
    }

    static Node newNode(int data) {
        Node temp = new Node(data);
        return temp;
    }

    static Node insert(Node node, int data) {
        if (node == null) {
            return (newNode(data));
        } else {
            if (data <= node.data) {
                node.left = insert(node.left, data);
            } else {
                node.right = insert(node.right, data);
            }
            return node;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        root = new Node(arr[0]);
        for (int i = 1; i < n; i++) {
            insert(root, arr[i]);
        }
        inorder(root, n);
        System.out.println(minNode.data);
    }
}
