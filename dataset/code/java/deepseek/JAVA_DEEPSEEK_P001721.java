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

    static Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        } else {
            Node cur;
            if (data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    static void inorder(Node root, int level, int[] sum) {
        if (root != null) {
            inorder(root.left, level + 1, sum);
            if (level % 2 != 0) {
                sum[0] += root.data;
            }
            inorder(root.right, level + 1, sum);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            int data = sc.nextInt();
            root = insert(root, data);
        }
        int[] sum = new int[1];
        inorder(root, 1, sum);
        System.out.println(sum[0]);
    }
}
