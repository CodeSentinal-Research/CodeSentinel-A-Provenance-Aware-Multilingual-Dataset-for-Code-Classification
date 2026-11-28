import java.util.*;

public class Main {
    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
        }
    }

    static Node buildTree(List<Integer> preorder, List<Integer> inorder, int startPreorder, int endPreorder, int startInorder, int endInorder) {
        if (startPreorder > endPreorder) {
            return null;
        }

        Node root = new Node(preorder.get(startPreorder));

        int index = inorder.indexOf(root.value);

        int leftSize = index - startInorder;

        root.left = buildTree(preorder, inorder, startPreorder + 1, startPreorder + leftSize, startInorder, index - 1);
        root.right = buildTree(preorder, inorder, startPreorder + leftSize + 1, endPreorder, index + 1, endInorder);

        return root;
    }

    static void printTree(Node root) {
        if (root == null) {
            return;
        }

        System.out.print(root.value + " ");
        printTree(root.left);
        printTree(root.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine();

        List<Integer> preorder = new ArrayList<>();
        List<Integer> inorder = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            preorder.add(scanner.nextInt());
        }

        for (int i = 0; i < n; i++) {
            inorder.add(scanner.nextInt());
        }

        Node root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1);

        printTree(root);
    }
}
