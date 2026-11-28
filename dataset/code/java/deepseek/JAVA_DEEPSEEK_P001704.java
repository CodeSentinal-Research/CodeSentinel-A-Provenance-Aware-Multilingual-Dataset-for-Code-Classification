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

    static boolean isIsomorphic(Node n1, Node n2) {
        if (n1 == null && n2 == null)
            return true;

        if (n1 == null || n2 == null)
            return false;

        if (n1.data != n2.data)
            return false;

        return (isIsomorphic(n1.left, n2.left) && isIsomorphic(n1.right, n2.right))
                || (isIsomorphic(n1.left, n2.right) && isIsomorphic(n1.right, n2.left));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        Node[] nodes1 = new Node[n1];
        for (int i = 0; i < n1; i++) {
            int data = sc.nextInt();
            nodes1[i] = new Node(data);
        }
        for (int i = 0; i < n1; i++) {
            int left = sc.nextInt();
            int right = sc.nextInt();
            if (left != 0) {
                nodes1[i].left = nodes1[left - 1];
            }
            if (right != 0) {
                nodes1[i].right = nodes1[right - 1];
            }
        }
        int n2 = sc.nextInt();
        Node[] nodes2 = new Node[n2];
        for (int i = 0; i < n2; i++) {
            int data = sc.nextInt();
            nodes2[i] = new Node(data);
        }
        for (int i = 0; i < n2; i++) {
            int left = sc.nextInt();
            int right = sc.nextInt();
            if (left != 0) {
                nodes2[i].left = nodes2[left - 1];
            }
            if (right != 0) {
                nodes2[i].right = nodes2[right - 1];
            }
        }
        System.out.println(isIsomorphic(nodes1[0], nodes2[0]) ? "YES" : "NO");
    }
}
