import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] nodes = line.split(" ");
            int left = Integer.parseInt(nodes[0]);
            int right = Integer.parseInt(nodes[1]);

            if (left != -1) {
                Node leftNode = new Node(left);
                Node rightNode = new Node(right);
                Node.children.put(leftNode, rightNode);
            }

            if (right != -1) {
                Node rightNode = new Node(right);
                Node.children.put(rightNode, null);
            }
        }

        Node root = findRoot();
        printInorder(root);
    }

    static class Node {
        int data;
        Node left;
        Node right;
        static java.util.Map<Node, Node> children = new java.util.HashMap<>();

        Node(int data) {
            this.data = data;
        }
    }

    static Node findRoot() {
        for (Node node : Node.children.keySet()) {
            if (Node.children.get(node).left == null && Node.children.get(node).right == null) {
                return node;
            }
        }
        return null;
    }

    static void printInorder(Node node) {
        if (node == null) {
            return;
        }
        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }
}
