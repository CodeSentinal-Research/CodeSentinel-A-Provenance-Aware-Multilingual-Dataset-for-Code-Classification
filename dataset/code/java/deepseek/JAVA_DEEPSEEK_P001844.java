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
        int size;
        int min;
        int max;
        boolean isBST;
        boolean isComplete;

        Result(int size, int min, int max, boolean isBST, boolean isComplete) {
            this.size = size;
            this.min = min;
            this.max = max;
            this.isBST = isBST;
            this.isComplete = isComplete;
        }
    }

    static int maxSize = 0;

    static Result largestBST(Node root) {
        if (root == null) {
            return new Result(0, Integer.MAX_VALUE, Integer.MIN_VALUE, true, true);
        }

        Result left = largestBST(root.left);
        Result right = largestBST(root.right);

        if (left.isBST && right.isBST && root.val > left.max && root.val < right.min) {
            if ((root.left == null ? 0 : left.size) + (root.right == null ? 0 : right.size) + 1 > maxSize) {
                maxSize = (root.left == null ? 0 : left.size) + (root.right == null ? 0 : right.size) + 1;
            }
            return new Result(
                    (root.left == null ? 0 : left.size) + (root.right == null ? 0 : right.size) + 1,
                    Math.min(root.val, left.min),
                    Math.max(root.val, right.max),
                    true,
                    left.isComplete && right.isComplete && (left.isComplete ? root.left == null : root.right == null)
            );
        }

        return new Result(
                Math.max((root.left == null ? 0 : left.size), (root.right == null ? 0 : right.size)),
                Integer.MIN_VALUE,
                Integer.MAX_VALUE,
                false,
                false
        );
    }

    public static void main(String[] args) {
        Node root = new Node(50);
        root.left = new Node(30);
        root.right = new Node(70);
        root.left.left = new Node(20);
        root.left.right = new Node(40);
        root.right.left = new Node(60);
        root.right.right = new Node(80);

        largestBST(root);
        System.out.println(maxSize);
    }
}
