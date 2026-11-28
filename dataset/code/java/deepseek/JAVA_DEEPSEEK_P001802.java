import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = right = null;
    }
}

public class Main {
    Node head;

    Node sortedListToBST(int n) {
        if (n <= 0)
            return null;

        Node left = sortedListToBST(n / 2);

        Node root = new Node(head.data);

        root.left = left;

        head = head.right;

        root.right = sortedListToBST(n - n / 2 - 1);

        return root;
    }

    void printInorder(Node node) {
        if (node == null)
            return;

        printInorder(node.left);

        System.out.print(node.data + " ");

        printInorder(node.right);
    }

    public static void main(String[] args) {
        Main tree = new Main();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        tree.head = new Node(sc.nextInt());
        for (int i = 1; i < n; i++) {
            Node temp = tree.head;
            while (temp.right != null) {
                temp = temp.right;
            }
            temp.right = new Node(sc.nextInt());
            temp.right.left = temp;
        }
        Node root = tree.sortedListToBST(n);
        tree.printInorder(root);
    }
}
