import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private void inorder(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        inorder(node.left, vals);
        vals.add(node.val);
        inorder(node.right, vals);
    }

    public boolean findTriplet(TreeNode root, int target) {
        List<Integer> vals = new ArrayList<>();
        inorder(root, vals);
        int n = vals.size();

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = vals.get(i) + vals.get(l) + vals.get(r);
                if (sum == target) return true;
                else if (sum < target) l++;
                else r--;
            }
        }
        return false;
    }
}