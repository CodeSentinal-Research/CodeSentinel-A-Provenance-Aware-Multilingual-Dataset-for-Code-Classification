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

    int index;

    Node constructTree(int postOrder[], int start, int end, int size) {
        if (index < 0 || start > end) {
            return null;
        }

        Node node = new Node(postOrder[index--]);

        if (start == end) {
            return node;
        }

        if (postOrder[index] > node.data) {
            return node;
        }

        node.right = constructTree(postOrder, postOrder[index] + 1, end, size);
        node.left = constructTree(postOrder, start, postOrder[index] - 1, size);

        return node;
    }

    void printInorder(Node node) {
        if (node == null) {
            return;
        }

        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int postOrder[] = new int[n];
        for (int i = 0; i < n; i++) {
            postOrder[i] = scanner.nextInt();
        }

        BinaryTree tree = new BinaryTree();
        tree.index = n - 1;
        Node root = tree.constructTree(postOrder, 0, n - 1, n);
        tree.printInorder(root);
    }
}
