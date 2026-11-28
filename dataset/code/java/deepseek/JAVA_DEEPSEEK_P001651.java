import java.util.Scanner;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    static Node buildTree(int[] preorder, int[] postorder) {
        if (preorder.length == 0 || postorder.length == 0)
            return null;

        Node root = new Node(postorder[postorder.length - 1]);

        int rootIndex = 0;
        for (int i = 0; i < preorder.length; i++) {
            if (preorder[i] == root.data) {
                rootIndex = i;
                break;
            }
        }

        int[] leftIn = new int[rootIndex];
        int[] rightIn = new int[preorder.length - rootIndex - 1];

        System.arraycopy(preorder, 0, leftIn, 0, rootIndex);
        System.arraycopy(postorder, 0, rightIn, 0, postorder.length - rootIndex - 1);

        root.left = buildTree(leftIn, rightIn);

        int[] leftPost = new int[rootIndex];
        int[] rightPost = new int[postorder.length - rootIndex - 1];

        System.arraycopy(postorder, 0, leftPost, 0, rootIndex);
        System.arraycopy(postorder, rootIndex, rightPost, 0, postorder.length - rootIndex - 1);

        root.right = buildTree(leftPost, rightPost);

        return root;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] preorder = new int[N];
        for (int i = 0; i < N; i++) {
            preorder[i] = scanner.nextInt();
        }
        int[] postorder = new int[N];
        for (int i = 0; i < N; i++) {
            postorder[i] = scanner.nextInt();
        }
        Node root = buildTree(preorder, postorder);
        // print the tree in the required traversal format
    }
}
