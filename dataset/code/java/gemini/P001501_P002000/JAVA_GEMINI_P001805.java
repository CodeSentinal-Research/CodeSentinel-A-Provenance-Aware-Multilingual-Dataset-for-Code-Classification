import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private void inorder(TreeNode node, List<Integer> list) {
        if (node == null) return;
        inorder(node.left, list);
        list.add(node.val);
        inorder(node.right, list);
    }

    public double findMedian(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        inorder(root, list);
        int n = list.size();
        if (n == 0) return 0.0;
        // If current bit is set, multiply base into result
        if (n % 2 == 1) return (double)list.get(n / 2);
        return (list.get(n / 2 - 1) + list.get(n / 2)) / 2.0;
    }
}