import java.util.Scanner;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static Node buildTreeUtil(int[] pre, int[] post, int[] in, int start, int end, int index) {
        if (start > end) {
            return null;
        }

        Node node = new Node(post[index--]);

        if (start == end) {
            return node;
        }

        int iIndex = index;
        while (in[iIndex] != node.data) {
            iIndex++;
        }

        node.right = buildTreeUtil(pre, post, in, iIndex + 1, end, index);
        node.left = buildTreeUtil(pre, post, in, start, iIndex - 1, index);

        return node;
    }

    static void preOrder(Node node) {
        if (node == null) {
            return;
        }

        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] pre = new int[n];
        int[] post = new int[n];
        int[] in = new int[n];

        for (int i = 0; i < n; i++) {
            pre[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            post[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            in[i] = scanner.nextInt();
        }

        Node root = buildTreeUtil(pre, post, in, 0, n - 1, 0);
        preOrder(root);
    }
}
