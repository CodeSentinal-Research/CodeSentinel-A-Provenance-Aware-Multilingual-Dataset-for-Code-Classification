import java.util.Scanner;

public class Main {
    public static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    public static Node insert(Node root, int data) {
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

    public static boolean isIdentical(Node a, Node b) {
        if (a == null && b == null)
            return true;
        if (a == null || b == null)
            return false;
        return (a.data == b.data && isIdentical(a.left, b.left) && isIdentical(a.right, b.right));
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        Node root1 = null;
        while (t-- > 0) {
            int data = scan.nextInt();
            root1 = insert(root1, data);
        }
        int t2 = scan.nextInt();
        Node root2 = null;
        while (t2-- > 0) {
            int data = scan.nextInt();
            root2 = insert(root2, data);
        }
        scan.close();
        boolean isIdentical = isIdentical(root1, root2);
        System.out.println(isIdentical ? "YES" : "NO");
    }
}
