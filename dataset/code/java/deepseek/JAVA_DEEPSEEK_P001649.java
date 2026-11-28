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

    static Node buildTree(int[] pre, int[] in, int startPre, int startIn, int endIn) {
        if (startIn > endIn) {
            return null;
        }

        Node node = new Node(pre[startPre]);
        int index = -1;
        for (int i = startIn; i <= endIn; i++) {
            if (in[i] == pre[startPre]) {
                index = i;
                break;
            }
        }

        startPre++;
        node.left = buildTree(pre, in, startPre, startIn, index - 1);
        node.right = buildTree(pre, in, startPre + index - startIn, index + 1, endIn);

        return node;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] pre = new int[N];
        int[] in = new int[N];

        for (int i = 0; i < N; i++) {
            pre[i] = scanner.nextInt();
        }

        for (int i = 0; i < N; i++) {
            in[i] = scanner.nextInt();
        }

        Node root = buildTree(pre, in, 0, 0, N - 1);

        // Print the reconstructed tree in the required traversal format.
        // You can use a recursive function to print the tree in inorder traversal format.
    }
}
