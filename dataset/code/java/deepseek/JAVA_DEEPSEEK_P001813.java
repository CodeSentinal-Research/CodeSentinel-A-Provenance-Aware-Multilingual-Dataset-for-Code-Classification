import java.util.*;

public class Main {
    static class Node {
        int key;
        Node left, right;

        Node(int item) {
            key = item;
            left = right = null;
        }
    }

    static Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        }

        return node;
    }

    static int closest(Node root, int target) {
        int closest = root.key;

        while (root != null) {
            if (Math.abs(closest - target) >= Math.abs(root.key - target)) {
                closest = root.key;
            }
            root = (root.key > target) ? root.left : root.right;
        }

        return closest;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        while (n-- > 0) {
            root = insert(root, scanner.nextInt());
        }
        int target = scanner.nextInt();
        System.out.println(closest(root, target));
    }
}
