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

    static int minValue(Node node) {
        Node current = node;
        while (current.left != null) {
            current = current.left;
        }
        return current.data;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            int data = sc.nextInt();
            root = insert(root, data);
        }
        System.out.println(minValue(root));
    }
}
