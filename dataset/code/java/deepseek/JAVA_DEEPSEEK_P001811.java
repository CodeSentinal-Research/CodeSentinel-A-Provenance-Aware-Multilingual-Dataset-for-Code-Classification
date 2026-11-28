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

    int largestBSTSubtree(Node node) {
        if (node == null)
            return 0;

        if (isBST(node, null, null))
            return sizeOfTree(node);

        return Math.max(largestBSTSubtree(node.left), largestBSTSubtree(node.right));
    }

    int sizeOfTree(Node node) {
        if (node == null)
            return 0;
        return sizeOfTree(node.left) + sizeOfTree(node.right) + 1;
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
        System.out.println(tree.largestBSTSubtree(tree.root));
    }
}
