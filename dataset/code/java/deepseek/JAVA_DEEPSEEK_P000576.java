import java.util.*;

public class Main {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<List<Integer>> verticalOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        Map<Integer, List<Integer>> columnMap = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Queue<Integer> columnQueue = new LinkedList<>();

        queue.add(root);
        columnQueue.add(0);

        int minColumn = 0;
        int maxColumn = 0;

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            int column = columnQueue.poll();

            if (node.left != null) {
                queue.add(node.left);
                columnQueue.add(column - 1);
                minColumn = Math.min(minColumn, column - 1);
            }

            if (node.right != null) {
                queue.add(node.right);
                columnQueue.add(column + 1);
                maxColumn = Math.max(maxColumn, column + 1);
            }

            if (!columnMap.containsKey(column)) {
                columnMap.put(column, new ArrayList<>());
            }

            columnMap.get(column).add(node.val);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = minColumn; i <= maxColumn; i++) {
            result.add(columnMap.get(i));
        }

        return result;
    }
}
