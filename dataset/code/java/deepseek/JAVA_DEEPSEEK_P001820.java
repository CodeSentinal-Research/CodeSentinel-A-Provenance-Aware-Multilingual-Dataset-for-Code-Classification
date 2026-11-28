import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        int leftSize;
        Node(int val) {
            this.val = val;
            leftSize = 0;
        }
    }

    Node root;

    void insert(int val) {
        root = insert(root, val);
    }

    Node insert(Node node, int val) {
        if (node == null) {
            return new Node(val);
        }
        if (val < node.val) {
            node.left = insert(node.left, val);
            node.leftSize++;
        } else if (val > node.val) {
            node.right = insert(node.right, val);
        }
        return node;
    }

    int findKth(int k) {
        return findKth(root, k).val;
    }

    Node findKth(Node node, int k) {
        if (node == null) {
            return null;
        }
        if (node.leftSize == k) {
            return node;
        } else if (node.leftSize > k) {
            return findKth(node.left, k);
        } else {
            return findKth(node.right, k - node.leftSize - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Main bst = new Main();
        for (int i = 0; i < n; i++) {
            bst.insert(scanner.nextInt());
        }
        int k = scanner.nextInt();
        System.out.println(bst.findKth(k));
    }
}
