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

    static void inorder(Node node, ArrayList<Integer> arr) {
        if (node == null)
            return;
        inorder(node.left, arr);
        arr.add(node.data);
        inorder(node.right, arr);
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

    static void replace(Node node, ArrayList<Integer> arr) {
        if (node == null)
            return;
        replace(node.left, arr);
        replace(node.right, arr);
        if (node.left != null || node.right != null) {
            int sum = 0;
            for (int i = 0; i < arr.size(); i++) {
                sum += arr.get(i);
            }
            node.data = sum;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        root = null;
        for (int i = 0; i < n; i++) {
            int data = sc.nextInt();
            root = insert(root, data);
        }
        ArrayList<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        replace(root, arr);
        inorder(root, arr);
        for (int i = 0; i < arr.size(); i++) {
            System.out.print(arr.get(i) + " ");
        }
    }
}
