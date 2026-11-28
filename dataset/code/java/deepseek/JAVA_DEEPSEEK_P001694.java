import java.util.*;

public class Main {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    private TreeNode targetNode;
    private int minDistance = Integer.MAX_VALUE;
    private TreeNode closestLeafNode;

    public void dfs(TreeNode node, boolean isLeaf) {
        if (node == null) return;
        if (node == targetNode) {
            minDistance = 0;
            return;
        }
        if (isLeaf && minDistance > (node.val & 1)) {
            minDistance = node.val & 1;
            closestLeafNode = node;
        }
        dfs(node.left, false);
        dfs(node.right, false);
    }

    public TreeNode findClosestLeafNode(TreeNode root, TreeNode target) {
        targetNode = target;
        dfs(root, true);
        return closestLeafNode;
    }

    public static void main(String[] args) {
        // Assuming the input is provided in the form of a list of nodes
        // where each node is represented as [value, leftChildValue, rightChildValue]
        // and the target node value is given as well.
        // This is a simplified representation and in a real scenario, the input would be provided in a different format.

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        TreeNode[] nodes = new TreeNode[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new TreeNode(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            if (left != -1) {
                nodes[i].left = nodes[left];
            }
            if (right != -1) {
                nodes[i].right = nodes[right];
            }
        }
        int targetValue = scanner.nextInt();
        TreeNode target = nodes[targetValue];

        Main solution = new Main();
        TreeNode closestLeafNode = solution.findClosestLeafNode(nodes[0], target);
        System.out.println(closestLeafNode.val);
    }
}
