import java.util.*;

public class Main {
    public static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    public static Node buildTree(int[] inOrder, int[] levelOrder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return null;
        }

        Node node = new Node(levelOrder[0]);

        if (inStart == inEnd) {
            return node;
        }

        int inIndex = search(inOrder, inStart, inEnd, node.data);

        int[] leftLevelOrder = Arrays.copyOfRange(levelOrder, 1, inIndex - inStart + 1);
        int[] rightLevelOrder = Arrays.copyOfRange(levelOrder, inIndex - inStart + 1, levelOrder.length);

        node.left = buildTree(inOrder, leftLevelOrder, inStart, inIndex - 1);
        node.right = buildTree(inOrder, rightLevelOrder, inIndex + 1, inEnd);

        return node;
    }

    public static int search(int[] arr, int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] levelOrder = new int[n];
        int[] inOrder = new int[n];

        for (int i = 0; i < n; i++) {
            levelOrder[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            inOrder[i] = scanner.nextInt();
        }

        Node root = buildTree(inOrder, levelOrder, 0, n - 1);

        // Print the reconstructed tree in the required traversal format.
        // Here, we are assuming that the traversal format is preorder.
        // You can modify this part according to your requirement.
        preOrder(root);
    }

    public static void preOrder(Node node) {
        if (node == null) {
            return;
        }

        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }
}
