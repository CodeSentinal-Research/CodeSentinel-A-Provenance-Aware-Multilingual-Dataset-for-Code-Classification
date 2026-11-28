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
    static int maxSize = 0;

    static boolean isComplete(Node root) {
        if (root == null)
            return true;

        Queue<Node> q = new LinkedList<>();
        q.add(root);

        boolean flag = false;
        while (!q.isEmpty()) {
            Node temp = q.poll();

            if (temp.left != null) {
                if (flag)
                    return false;
                q.add(temp.left);
            } else
                flag = true;

            if (temp.right != null) {
                if (flag)
                    return false;
                q.add(temp.right);
            } else
                flag = true;
       }

        return true;
    }

    static boolean isFull(Node root) {
        if (root == null)
            return true;

        if (root.left == null && root.right == null)
            return true;

        if ((root.left != null) && (root.right != null))
            return (isFull(root.left) && isFull(root.right));

        return false;
    }

    static void largestPerfectSubtree(Node root) {
        if (root != null) {
            if (isComplete(root) && isFull(root)) {
                int size = countNodes(root);
                if (size > maxSize)
                    maxSize = size;
            }
            largestPerfectSubtree(root.left);
            largestPerfectSubtree(root.right);
        }
    }

    static int countNodes(Node root) {
        if (root == null)
            return 0;
        return (1 + countNodes(root.left) + countNodes(root.right));
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        largestPerfectSubtree(root);
        System.out.println(maxSize);
    }
}
