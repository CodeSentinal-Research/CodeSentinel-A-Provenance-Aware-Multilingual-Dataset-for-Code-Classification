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
    static Node node;
    static int k;

    static void inorder(Node node, int k) {
        if (node == null || k < 0)
            return;

        inorder(node.left, k);
        k--;
        if (k == 0) {
            System.out.println(node.data);
            return;
        }
        inorder(node.right, k);
    }

    static Node newNode(int data) {
        Node temp = new Node(data);
        return temp;
    }

    static Node insert(Node node, int data) {
        if (node == null) {
            return (newNode(data));
        } else {
            Node temp = null;
            if (data <= node.data) {
                temp = insert(node.left, data);
                node.left = temp;
                temp.right = node;
            } else {
                temp = insert(node.right, data);
                node.right = temp;
                temp.left = node;
            }
            return (node);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        root = null;
        while (n-- > 0) {
            int num = sc.nextInt();
            root = insert(root, num);
        }
        int target = sc.nextInt();
        k = sc.nextInt();
        node = root;
        while (node.data != target) {
            if (node.data < target) {
                node = node.right;
            } else {
                node = node.left;
            }
        }
        inorder(node, k);
    }
}
