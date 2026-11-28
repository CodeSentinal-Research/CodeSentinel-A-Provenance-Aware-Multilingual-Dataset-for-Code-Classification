import java.util.Scanner;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        int size;

        Node(int val) {
            this.val = val;
            left = null;
            right = null;
            size = 1;
        }
    }

    static Node root;

    static Node insert(Node node, int val) {
        if (node == null) {
            return new Node(val);
        }
        if (val < node.val) {
            node.left = insert(node.left, val);
        } else if (val > node.val) {
            node.right = insert(node.right, val);
        }
        node.size++;
        return node;
    }

    static double findMedian() {
        if (root == null) {
            return 0;
        }
        if (root.size % 2 == 0) {
            return (findKth(root, root.size / 2) + findKth(root, root.size / 2 + 1)) / 2.0;
        } else {
            return findKth(root, root.size / 2 + 1);
        }
    }

    static int findKth(Node node, int k) {
        int leftSize = node.left != null ? node.left.size : 0;
        if (k <= leftSize) {
            return findKth(node.left, k);
        } else if (k > node.size - leftSize) {
            return findKth(node.right, k - node.size + leftSize);
        } else {
            return node.val;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        root = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            root = insert(root, val);
        }
        System.out.println(findMedian());
    }
}
