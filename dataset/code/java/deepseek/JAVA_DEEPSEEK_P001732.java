import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right, inorderSuccessor;

        Node(int item) {
            data = item;
            left = right = inorderSuccessor = null;
        }
    }

    Node root;

    Node buildTree(int inorder[], int start, int end) {
        if (start > end)
            return null;

        int i = maxIndex(inorder, start, end);
        Node node = new Node(inorder[i]);

        if (start == end)
            return node;

        node.left = buildTree(inorder, start, i - 1);
        node.right = buildTree(inorder, i + 1, end);

        return node;
    }

    int maxIndex(int arr[], int start, int end) {
        int i, max = arr[start];
        int maxIndex = start;
        for (i = start + 1; i <= end; i++) {
            if (arr[i] > max) {
                max = arr[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    void inOrder(Node node) {
        if (node == null)
            return;

        inOrder(node.left);
        System.out.print(node.data + " ");
        inOrder(node.right);
    }

    boolean isValid(Node root) {
        if (root == null)
            return true;

        if (root.left == null && root.right == null)
            return true;

        if (root.left == null || root.right == null)
            return false;

        return isValid(root.left) && isValid(root.right);
    }

    public static void main(String[] args) {
        Main tree = new Main();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] inorder = new int[n];
        for (int i = 0; i < n; i++) {
            inorder[i] = sc.nextInt();
        }
        tree.root = tree.buildTree(inorder, 0, n - 1);
        if (tree.isValid(tree.root)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
