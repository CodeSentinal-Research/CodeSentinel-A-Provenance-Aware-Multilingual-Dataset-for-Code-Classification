import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        TreeNode[] nodes = new TreeNode[n];
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");
            nodes[i] = new TreeNode(Integer.parseInt(parts[0]));
            if (parts.length > 1) {
                nodes[i].left = nodes[Integer.parseInt(parts[1])];
                if (parts.length > 2) {
                    nodes[i].right = nodes[Integer.parseInt(parts[2])];
                }
            }
        }

        TreeNode root = nodes[0];
        System.out.println(longestZigZag(root));
    }

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    static int longestZigZag(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int[] left = longestZigZagHelper(root.left);
        int[] right = longestZigZagHelper(root.right);

        return Math.max(
                Math.max(left[0], right[0]),
                Math.max(left[1], right[1])
        );
    }

    static int[] longestZigZagHelper(TreeNode root) {
        if (root == null) {
            return new int[]{0, 0};
        }

        int[] left = longestZigZagHelper(root.left);
        int[] right = longestZigZagHelper(root.right);

        int[] result = new int[2];
        result[0] = Math.max(
                Math.max(left[0], right[0]),
                left[1] + right[1] + 1
        );
        result[1] = Math.max(
                Math.max(left[0], right[0]),
                Math.max(left[1], right[1])
        );

        return result;
    }
}
