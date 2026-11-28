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

    static boolean isDeadEnd(Node root) {
        return isDeadEndUtil(root, 1, Integer.MAX_VALUE);
    }

    static boolean isDeadEndUtil(Node root, int min, int max) {
        if (root == null)
            return false;

        if (max - min <= 1)
            return true;

        return (isDeadEndUtil(root.left, min, root.data - 1) || 
                isDeadEndUtil(root.right, root.data + 1, max));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            int val = sc.nextInt();
            root = insert(root, val);
        }
        if (isDeadEnd(root))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
