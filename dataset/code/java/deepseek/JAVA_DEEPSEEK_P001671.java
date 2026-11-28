import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            int left = Integer.parseInt(input[0]);
            int right = Integer.parseInt(input[1]);

            // Assuming the tree is a binary tree
            // Assuming the tree is a complete binary tree
            // Assuming the tree is a binary tree with no more than 2 children
            Node root = new Node(left);
            Node curr = root;
            for (int j = 1; j < 2; j++) {
                String[] children = scanner.nextLine().split(" ");
                int child = Integer.parseInt(children[0]);
                if (j == 1) {
                    curr.left = new Node(child);
                    curr = curr.left;
                } else {
                    curr.right = new Node(child);
                    curr = curr.right;
                }
            }

            MorrisInorderTraversal morrisInorderTraversal = new MorrisInorderTraversal(root);
            morrisInorderTraversal.printInorder();
            System.out.println();
        }

        scanner.close();
    }
}

class Node {
    int val;
    Node left;
    Node right;

    Node(int val) {
        this.val = val;
    }
}

class MorrisInorderTraversal {
    Node root;
    Node prev, curr;

    MorrisInorderTraversal(Node root) {
        this.root = root;
        this.prev = null;
        this.curr = null;
    }

    void printInorder() {
        if (root == null) return;

        curr = root;
        while (curr != null) {
            if (curr.left == null) {
                printNode(curr);
                curr = curr.right;
            } else {
                prev = curr.left;
                while (prev.right != null && prev.right != curr) {
                    prev = prev.right;
                }

                if (prev.right == null) {
                    prev.right = curr;
                    curr = curr.left;
                } else {
                    printNode(curr);
                    prev.right = null;
                    curr = curr.right;
                }
            }
        }
    }

    void printNode(Node node) {
        System.out.print(node.val + " ");
    }
}
