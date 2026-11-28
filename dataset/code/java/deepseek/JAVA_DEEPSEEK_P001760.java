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

    static Node newNode(int data) {
        Node temp = new Node(data);
        return temp;
    }

    static Node insert(Node node, int data) {
        if (node == null) {
            return newNode(data);
        } else {
            if (node.data < data) {
                node.right = insert(node.right, data);
            } else if (node.data > data) {
                node.left = insert(node.left, data);
            }
        }
        return node;
    }

    static int sum(Node root) {
        if (root == null)
            return 0;
        int sum = 0;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node temp = q.peek();
            sum += temp.data;
            q.remove();
            if (temp.left != null)
                q.add(temp.left);
            if (temp.right != null)
                q.add(temp.right);
        }
        return sum;
    }

    static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
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
        int sum = sum(root);
        inorder(root);
    }
}
