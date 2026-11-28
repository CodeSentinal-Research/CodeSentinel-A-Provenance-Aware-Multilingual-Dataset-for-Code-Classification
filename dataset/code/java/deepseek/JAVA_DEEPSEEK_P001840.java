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
    static int index;

    Node constructTree(int[] pre, int low, int high) {
        if (index > pre.length || low > high) {
            return null;
        }

        Node node = new Node(pre[index++]);

        if (low == high) {
            return node;
        }

        int i;
        for (i = low; i <= high; ++i) {
            if (pre[i] > node.data) {
                break;
            }
        }

        node.left = constructTree(pre, index, i - 1);
        node.right = constructTree(pre, i, high);

        return node;
    }

    void printInorder(Node node) {
        if (node == null) {
            return;
        }

        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        int[] pre = new int[n];
        for (int i = 0; i < n; i++) {
            pre[i] = Integer.parseInt(str[i]);
        }

        Main tree = new Main();
        root = tree.constructTree(pre, 0, n - 1);
        tree.printInorder(root);
    }
}
