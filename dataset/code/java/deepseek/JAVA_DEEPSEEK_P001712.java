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

    static int max(int a, int b) {
        return (a >= b) ? a : b;
    }

    static int height(Node node) {
        if (node == null)
            return 0;
        return (1 + max(height(node.left), height(node.right)));
    }

    static void printCurrentLevel(Node node, int level) {
        if (node == null)
            return;
        if (level == 1)
            System.out.print(node.data + " ");
        else if (level > 1) {
            printCurrentLevel(node.left, level - 1);
            printCurrentLevel(node.right, level - 1);
        }
    }

    static void printLevelOrder(Node node) {
        int h = height(node);
        for (int i = 1; i <= h; i++)
            printCurrentLevel(node, i);
    }

    static Node constructTree(int arr[], Node node, int i) {
        if (i < arr.length) {
            Node temp = new Node(arr[i]);
            node = temp;

            node.left = constructTree(arr, node.left, 2 * i + 1);

            node.right = constructTree(arr, node.right, 2 * i + 2);
        }
        return node;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Node root = null;
        root = constructTree(arr, root, 0);
        printLevelOrder(root);
    }
}
