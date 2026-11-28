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

    static boolean isCousin(Node node, int a, int b, int level, int parent) {
        if (node == null)
            return false;

        if (node.data == a || node.data == b) {
            if (node.data == a) {
                return (level == b && parent != node.data);
            } else {
                return (level == a && parent != node.data);
           }
        }

        boolean left = false, right = false;
        if (node.left != null) {
            left = isCousin(node.left, a, b, level + 1, node.data);
        }
        if (node.right != null) {
            right = isCousin(node.right, a, b, level + 1, node.data);
        }

        return left || right;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        root = new Node(1);
        for (int i = 1; i < n; i++) {
            int parent = sc.nextInt();
            String child = sc.next();
            if (child.equals("L")) {
                root.left = new Node(i + 1);
            } else {
                root.right = new Node(i + 1);
            }
        }
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (isCousin(root, a, b, 0, -1)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
