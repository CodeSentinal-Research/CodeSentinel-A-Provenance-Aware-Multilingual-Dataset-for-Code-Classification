import java.util.Scanner;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;

        Node(int val) {
            this.val = val;
        }
    }

    static int maxUnivalSubtree(Node root, int[] max) {
        if (root == null) {
            return Integer.MAX_VALUE;
        }

        int left = maxUnivalSubtree(root.left, max);
        int right = maxUnivalSubtree(root.right, max);

        if (left == Integer.MAX_VALUE && right == Integer.MAX_VALUE) {
            max[0] = Math.max(max[0], 1);
            return root.val;
        }

        if (root.val == left && root.val == right) {
            max[0] = Math.max(max[0], 2);
            return root.val;
        }

        return Integer.MAX_VALUE;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            int left = scanner.nextInt() - 1;
            int right = scanner.nextInt() - 1;
            if (left != -1) {
                nodes[i].left = nodes[left];
            }
            if (right != -1) {
                nodes[i].right = nodes[right];
            }
        }
        int[] max = new int[1];
        maxUnivalSubtree(nodes[0], max);
        System.out.println(max[0]);
    }
}
