import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static class Result {
        int maxSum;
        int sum;
        int min;
        int max;

        Result(int maxSum, int sum, int min, int max) {
            this.maxSum = maxSum;
            this.sum = sum;
            this.min = min;
            this.max = max;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            if (left != -1) {
                nodes[i].left = nodes[left - 1];
            }
            if (right != -1) {
                nodes[i].right = nodes[right - 1];
            }
        }
        Result result = maxSumBST(nodes[0]);
        System.out.println(result.maxSum);
    }

    private static Result maxSumBST(Node node) {
        if (node == null) {
            return new Result(0, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);
        }
        Result left = maxSumBST(node.left);
        Result right = maxSumBST(node.right);
        if (left.max < node.val && node.val < right.min) {
            int sum = left.sum + right.sum + node.val;
            int maxSum = Math.max(sum, Math.max(left.maxSum, right.maxSum));
            return new Result(maxSum, sum, Math.min(node.val, left.min), Math.max(node.val, right.max));
        } else {
            return left.sum > right.sum ? left : right;
        }
    }
}
