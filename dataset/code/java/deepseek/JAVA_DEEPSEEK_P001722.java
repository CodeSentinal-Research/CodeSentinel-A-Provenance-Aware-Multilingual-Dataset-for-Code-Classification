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

    static int sumAtEvenLevels(Node root, int level) {
        if (root == null)
            return 0;

        if (level % 2 == 0)
            return root.data + sumAtEvenLevels(root.left, level + 1) + sumAtEvenLevels(root.right, level + 1);
        else
            return sumAtEvenLevels(root.left, level + 1) + sumAtEvenLevels(root.right, level + 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            int val = sc.nextInt();
            root = insert(root, val);
        }
        System.out.println(sumAtEvenLevels(root, 0));
    }
}
