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

    static void inorder(Node node, int target) {
        if (node == null)
            return;

        inorder(node.left, target);
        if (node.data == target) {
            ancestorCount(node);
        }
        inorder(node.right, target);
    }

    static int ancestorCount(Node node) {
        if (node == null)
            return 0;

        int count = 1 + ancestorCount(node.left) + ancestorCount(node.right);
        System.out.println(node.data + ": " + count);
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        root = new Node(1);
        for (int i = 1; i < n; i++) {
            int parent = sc.nextInt();
            int child = sc.nextInt();
            Node parentNode = findNode(root, parent);
            if (parentNode.left == null) {
                parentNode.left = new Node(child);
            } else {
                parentNode.right = new Node(child);
            }
        }
        int target = sc.nextInt();
        inorder(root, target);
    }

    static Node findNode(Node node, int target) {
        if (node == null)
            return null;
        if (node.data == target)
            return node;
        Node found = findNode(node.left, target);
        if (found != null)
            return found;
        return findNode(node.right, target);
    }
}
