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

    private void addLeaves(TreeNode node, List<Integer> res) {
        if (isLeaf(node)) {
            res.add(node.val);
            return;
        }
        if (node.left != null) addLeaves(node.left, res);
        if (node.right != null) addLeaves(node.right, res);
    }

    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        if (!isLeaf(root)) res.add(root.val);

        TreeNode cur = root.left;
        while (cur != null) {
            if (!isLeaf(cur)) res.add(cur.val);
            cur = cur.left != null ? cur.left : cur.right;
        }

        addLeaves(root, res);

        Stack<Integer> st = new Stack<>();
        cur = root.right;
        while (cur != null) {
            if (!isLeaf(cur)) st.push(cur.val);
            cur = cur.right != null ? cur.right : cur.left;
        }
        while (!st.isEmpty()) res.add(st.pop());

        return res;
    }
}