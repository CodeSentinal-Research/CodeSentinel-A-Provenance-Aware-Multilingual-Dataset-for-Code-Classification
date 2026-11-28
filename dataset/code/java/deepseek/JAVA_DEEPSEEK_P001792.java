import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right, parent;

        Node(int item) {
            data = item;
            left = right = parent = null;
        }
    }

    static Node root;

    static Node insert(Node node, int data) {
        if (node == null) {
            return (new Node(data));
        } else {
            Node temp = null;
            if (data <= node.data) {
                temp = insert(node.left, data);
                node.left = temp;
                temp.parent = node;
           
              } else {
                temp = insert(node.right, data);
                node.right = temp;
                temp.parent = node;
            }
            return node;
        }
    }

    static Node search(Node root, int key) {
        while (root != null && root.data != key) {
            if (root.data > key) {
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return root;
    }

    static Node minValue(Node root) {
        Node current = root;
        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    static void inorderSuccessor(Node root, int key) {
        Node target = search(root, key);
        if (target == null) {
            System.out.println("NONE");
            return;
        }
        if (target.right != null) {
            Node min = minValue(target.right);
            System.out.println(min.data);
        } else {
            Node parent = target.parent;
            while (parent != null && target == parent.right) {
                target = parent;
                parent = parent.parent;
            }
            if (parent == null) {
                System.out.println("NONE");
            } else {
                System.out.println(parent.data);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        root = null;
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            root = insert(root, data);
        }
        int key = scanner.nextInt();
        inorderSuccessor(root, key);
    }
}
