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
        boolean isFull;

        Result(int size, int min, int max, boolean isBST, boolean isFull) {
            this.size = size;
            this.min = min;
            this.max = max;
            this.isBST = isBST;
            this.isFull = isFull;
        }
    }

    static int maxSize = 0;

    static Result largestBSTSubtree(Node root) {
        if (root == null) {
            return new Result(0, Integer.MAX_VALUE, Integer.MIN_VALUE, true, true);
        }

        Result left = largestBSTSubtree(root.left);
        Result right = largestBSTSubtree(root.right);

        if (left.isBST && right.isBST && root.val > left.max && root.val < right.min) {
            if ((root.left == null ? 0 : left.size) + (root.right == null ? 0 : right.size) + 1 > maxSize) {
                maxSize = (root.left == null ? 0 : left.size) + (root.right == null ? 0 : right.size) + 1;
            }
            return new Result(
                    (root.left == null ? 0 : left.size) + (root.right == null ? 0 : right.size) + 1,
                    Math.min(root.val, left.min),
                    Math.max(root.val, right.max),
                    true,
                    (root.left == null ? true : left.isFull) && (root.right == null ? true : right.isFull) &&
                            ((root.left == null ? 0 : left.size) == (root.right == null ? 0 : right.size) ||
                                    ((root.left == null ? 0 : left.size) + 1 == (root.right == null ? 0 : right.size)) ||
                                    ((root.left == null ? 0 : left.size) == (root.right == null ? 0 : right.size) + 1))
            );
        }

        return new Result(Math.max((root.left == null ? 0 : left.size), (root.right == null ? 0 : right.size)),
                Math.min(root.val, Math.min(left.min, right.min)),
                Math.max(root.val, Math.max(left.max, right.max)),
                false, false);
    }

    public static void main(String[] args) {
        // Assuming the input is a binary tree represented as a list of nodes
        List<Node> nodes = new ArrayList<>();
        // ...
        // Populate the nodes list with the input
        // ...
        largestBSTSubtree(nodes.get(0));
        System.out.println(maxSize);
    }
}
