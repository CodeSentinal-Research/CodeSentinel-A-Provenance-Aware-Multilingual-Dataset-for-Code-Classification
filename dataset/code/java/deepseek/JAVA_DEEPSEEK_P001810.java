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

    int addGreaterUtil(Node node, int sum) {
        if (node == null)
            return sum;

        sum = addGreaterUtil(node.right, sum);

        sum += node.data;
        node.data = sum;

        return addGreaterUtil(node.left, sum);
    }

    void addGreater(Node node) {
        addGreaterUtil(node, 0);
    }

    void printInorder(Node node) {
        if (node == null)
            return;

        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(sc.nextInt());
        for (int i = 1; i < n; i++) {
            tree.root = insert(tree.root, sc.nextInt());
        }
        tree.addGreater(tree.root);
        tree.printInorder(tree.root);
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
}
