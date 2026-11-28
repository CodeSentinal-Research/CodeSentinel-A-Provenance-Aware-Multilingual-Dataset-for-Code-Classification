import java.util.Scanner;

public class Main {
    public static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    public static Node flatten(Node root) {
        if (root == null) {
            return null;
        }

        Node left = flatten(root.left);
        Node right = flatten(root.right);

        root.left = null;
        root.right = left;

        Node temp = root;
        while (temp.right != null) {
            temp = temp.right;
        }
        temp.right = right;

        return root;
    }

    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.right;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        while (n-- > 0) {
            int data = scanner.nextInt();
            root = new Node(data);
            if (n == 1) {
                root.left = new Node(scanner.nextInt());
            } else {
                Node left = new Node(scanner.nextInt());
                Node right = new Node(scanner.nextInt());
                root.left = left;
                root.right = right;
            }
        }
        scanner.close();

        root = flatten(root);
        printList(root);
    }
}
