import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = new Node(sc.nextInt());
        for (int i = 1; i < n; i++) {
            insert(root, sc.nextInt());
        }
        int k = sc.nextInt();
        countPaths(root, k);
        System.out.println(count);
    }

    static void insert(Node node, int val) {
        if (val < node.val) {
            if (node.left == null) {
                node.left = new Node(val);
            } else {
                insert(node.left, val);
            }
        } else {
            if (node.right == null) {
                node.right = new Node(val);
            } else {
                insert(node.right, val);
            }
        }
    }

    static void countPaths(Node node, int k) {
        if (node == null) {
            return;
        }
        k -= node.val;
        if (k == 0 && node.left == null && node.right == null) {
            count++;
        }
        countPaths(node.left, k);
        countPaths(node.right, k);
    }
}
