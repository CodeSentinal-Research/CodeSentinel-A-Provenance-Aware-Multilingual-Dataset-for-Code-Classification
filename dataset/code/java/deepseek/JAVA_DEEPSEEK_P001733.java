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

    static int sum(Node root) {
        if (root == null)
            return 0;
        return sum(root.left) + root.data + sum(root.right);
    }

    static boolean isSumTree(Node root) {
        if (root == null || (root.left == null && root.right == null))
            return true;

        int ls = sum(root.left);
        int rs = sum(root.right);

        if (root.data != ls + rs)
            return false;

        return isSumTree(root.left) && isSumTree(root.right);
    }

    public static void main(String[] args) {
        Node root = new Node(26);
        root.left = new Node(10);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(6);
        root.right.right = new Node(3);

        if (isSumTree(root))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
