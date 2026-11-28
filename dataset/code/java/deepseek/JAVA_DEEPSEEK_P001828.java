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

    static boolean isIdentical(Node node1, Node node2) {
        if (node1 == null && node2 == null)
            return true;
        if (node1 == null || node2 == null)
            return false;
        return (node1.data == node2.data && isIdentical(node1.left, node2.left) && isIdentical(node1.right, node2.right));
    }

    static boolean isSubtree(Node T, Node S) {
        if (S == null)
            return true;
        if (T == null)
            return false;
        if (isIdentical(T, S))
            return true;
        return isSubtree(T.left, S) || isSubtree(T.right, S);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root1 = null;
        Node root2 = null;
        int n1 = sc.nextInt();
        for (int i = 0; i < n1; i++) {
            int data = sc.nextInt();
            root1 = insert(root1, data);
        }
        int n2 = sc.nextInt();
        for (int i = 0; i < n2; i++) {
            int data = sc.nextInt();
            root2 = insert(root2, data);
        }
        if (isSubtree(root1, root2))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
