import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private boolean isLeaf(TreeNode node) {
        return node != null && node.left == null && node.right == null;
    }

    private void addLeavesRev(TreeNode node, List<Integer> res) {
        if (isLeaf(node)) {
            res.add(node.val);
            return;
        }
        if (node.right != null) addLeavesRev(node.right, res);
        if (node.left != null) addLeavesRev(node.left, res);
    }

    public List<Integer> boundaryOfBinaryTreeClockwise(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        if (!isLeaf(root)) res.add(root.val);

        TreeNode cur = root.right;
        while (cur != null) {
            if (!isLeaf(cur)) res.add(cur.val);
            cur = cur.right != null ? cur.right : cur.left;
        }

        addLeavesRev(root, res);

        Stack<Integer> st = new Stack<>();
        cur = root.left;
        while (cur != null) {
            if (!isLeaf(cur)) st.push(cur.val);
            cur = cur.left != null ? cur.left : cur.right;
        }
        while (!st.isEmpty()) res.add(st.pop());

        return res;
    }
}