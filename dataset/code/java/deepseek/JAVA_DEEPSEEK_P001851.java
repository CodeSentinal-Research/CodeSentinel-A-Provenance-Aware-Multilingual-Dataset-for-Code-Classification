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

    static void insert(Node node, int data) {
        if (data < node.data) {
            if (node.left == null)
                node.left = new Node(data);
            else
                insert(node.left, data);
        } else if (data > node.data) {
            if (node.right == null)
                node.right = new Node(data);
            else
                insert(node.right, data);
        }
    }

    static void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.data + " ");
            inOrder(node.right);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] strs = br.readLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(strs[i]);
        }
        root = new Node(arr[0]);
        for (int i = 1; i < n; i++) {
            insert(root, arr[i]);
        }
        inOrder(root);
    }
}
