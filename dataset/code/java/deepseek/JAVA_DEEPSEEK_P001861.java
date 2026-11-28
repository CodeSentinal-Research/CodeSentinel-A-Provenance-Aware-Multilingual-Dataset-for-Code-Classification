import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    boolean isBST(Node node, Node left, Node right) {
        if (node == null)
            return true;

        if (left != null && node.data <= left.data)
            return false;

        if (right != null && node.data >= right.data)
            return false;

        return isBST(node.left, left, node) && isBST(node.right, node, right);
    }

    int diameter(Node node) {
        if (node == null)
            return 0;

        int leftHeight = height(node.left);
        int rightHeight = height(node.right);

        int leftDiameter = diameter(node.left);
        int rightDiameter = diameter(node.right);

        return Math.max(leftHeight + rightHeight + 1, Math.max(leftDiameter, rightDiameter));
    }

    int height(Node node) {
        if (node == null || (node.left == null && node.right == null))
            return 0;

        return Math.max(height(node.left), height(node.right)) + 1;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        BinaryTree tree = new BinaryTree();
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            tree.root = new Node(data);
        }
        if (tree.isBST(tree.root, null, null)) {
            System.out.println(tree.diameter(tree.root));
        } else {
            System.out.println("Not a BST");
        }
    }
}
