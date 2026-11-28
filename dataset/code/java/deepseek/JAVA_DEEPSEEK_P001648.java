import java.util.Arrays;
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

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    static class Serializer {
        String serialize(Node root) {
            StringBuilder sb = new StringBuilder();
            serialize(root, sb);
            return sb.toString();
        }

        void serialize(Node node, StringBuilder sb) {
            if (node == null) {
                sb.append("X,");
            } else {
                sb.append(node.data).append(",");
                serialize(node.left, sb);
                serialize(node.right, sb);
            }
        }

        Node deserialize(String data) {
            String[] values = data.split(",");
            return deserialize(values, 0, values.length - 1);
        }

        Node deserialize(String[] values, int start, int end) {
            if (start > end) {
                return null;
            }

            if (values[start].equals("X")) {
                return null;
            }

            Node node = new Node(Integer.parseInt(values[start]));
            node.left = deserialize(values, start + 1, end);
            node.right = deserialize(values, start + 2, end);
            return node;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        Serializer serializer = new Serializer();
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] values = line.split(" ");
            int[] nodes = new int[values.length];
            for (int j = 0; j < values.length; j++) {
                nodes[j] = Integer.parseInt(values[j]);
            }

            Node root = buildTree(nodes, 0, nodes.length - 1);
            String serialized = serializer.serialize(root);

            System.out.println(serialized);

            Node deserialized = serializer.deserialize(serialized);
            // Print the reconstructed tree in the required traversal format.
            // You can use the following code to print the tree in inorder traversal format.
            // printInorder(deserialized);
        }
    }

    static Node buildTree(int[] nodes, int start, int end) {
        if (start > end) {
            return null;
        }

        int mid = (start + end) / 2;
        Node node = new Node(nodes[mid]);
        node.left = buildTree(nodes, start, mid - 1);
        node.right = buildTree(nodes, mid + 1, end);
        return node;
    }

    // You can use the following code to print the tree in inorder traversal format.
    static void printInorder(TreeNode node) {
        if (node == null) {
            return;
        }

        printInorder(node.left);
        System.out.print(node.val + " ");
        printInorder(node.right);
    }
}
