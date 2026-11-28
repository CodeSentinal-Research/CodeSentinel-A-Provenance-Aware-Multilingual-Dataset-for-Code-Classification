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
    static int maxSum = Integer.MIN_VALUE;
    static Node maxNode;

    static Node insert(Node node, int data) {
        if (node == null) {
            return (new Node(data));
        } else {
            if (node.data < data) {
                node.right = insert(node.right, data);
            } else {
                node.left = insert(node.left, data);
            }
            return node;
        }
    }

    static int findSum(Node node) {
        if (node == null)
            return 0;
        int sum = node.data + findSum(node.left) + findSum(node.right);
        if (sum > maxSum) {
            maxSum = sum;
            maxNode = node;
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        String[] str = br.readLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }
        for (int i = 0; i < n; i++) {
            root = insert(root, arr[i]);
        }
        findSum(root);
        System.out.println(maxNode.data);
    }
}
