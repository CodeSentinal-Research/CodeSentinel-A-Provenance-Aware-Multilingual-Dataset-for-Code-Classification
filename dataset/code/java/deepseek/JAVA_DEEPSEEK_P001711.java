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

    static boolean isSumProperty(Node node) {
        int left_data = 0, right_data = 0;
        if (node == null || (node.left == null && node.right == null))
            return true;
        if (node.left != null)
            left_data = node.left.data;
        if (node.right != null)
            right_data = node.right.data;
        if ((left_data + right_data) == node.data && isSumProperty(node.left) && isSumProperty(node.right))
            return true;
        return false;
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(8);
        root.right = new Node(2);
        root.left.left = new Node(3);
        root.left.right = new Node(5);
        root.right.right = new Node(2);
        if (isSumProperty(root))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
