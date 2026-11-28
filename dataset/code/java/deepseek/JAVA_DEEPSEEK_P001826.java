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

    static boolean isSame(Node a, Node b) {
        if (a == null && b == null)
            return true;
        if (a == null || b == null)
            return false;
        return (a.data == b.data && isSame(a.left, b.left) && isSame(a.right, b.right));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n1 = Integer.parseInt(br.readLine().trim());
        Node root1 = null;
        while (n1-- > 0) {
            int data = Integer.parseInt(br.readLine().trim());
            root1 = insert(root1, data);
        }
        int n2 = Integer.parseInt(br.readLine().trim());
        Node root2 = null;
        while (n2-- > 0) {
            int data = Integer.parseInt(br.readLine().trim());
            root2 = insert(root2, data);
        }
        if (isSame(root1, root2)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
