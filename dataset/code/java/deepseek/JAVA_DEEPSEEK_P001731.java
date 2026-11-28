import java.util.Scanner;

class Node {
    int data;
    Node left;
    Node right;
    Node nextRight;

    Node(int item) {
        data = item;
        left = right = nextRight = null;
    }
}

class BinaryTree {
    Node root;

    void convertToThreaded(Node node) {
        if (node == null)
            return;

        convertToThreaded(node.left);
        convertToThreaded(node.right);

        if (node.right == null) {
            node.right = node.nextRight;
        }
    }

    void printThreaded(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.right;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(sc.nextInt());
        for (int i = 1; i < n; i++) {
            tree.root = new Node(sc.nextInt());
        }
        tree.convertToThreaded(tree.root);
        tree.printThreaded(tree.root);
    }
}
