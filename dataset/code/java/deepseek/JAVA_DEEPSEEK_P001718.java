import java.util.*;

public class Main {
    static int count = 0;
    static int k;

    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        } else {
            Node temp = null;
            if (data <= root.data) {
                temp = insert(root.left, data);
                root.left = temp;
            } else {
                temp = insert(root.right, data);
                root.right = temp;
            }

            return root;
        }
    }

    static void countPaths(Node root, int path[], int pathLen) {
        if (root == null)
            return;

        path[pathLen] = root.data;
        pathLen++;

        if (root.left == null && root.right == null) {
            if (pathLen - 1 == k) {
                count++;
            }
        } else {
            countPaths(root.left, path, pathLen);
            countPaths(root.right, path, pathLen);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        while (n-- > 0) {
            int data = scanner.nextInt();
            root = insert(root, data);
        }
        k = scanner.nextInt();
        int path[] = new int[1000];
        countPaths(root, path, 0);
        System.out.println(count);
    }
}
