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

    public int countPairs(TreeNode root1, TreeNode root2, int target) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        inorder(root1, list1);
        inorder(root2, list2);

        int i = 0, j = list2.size() - 1;
        int count = 0;

        while (i < list1.size() && j >= 0) {
            int curSum = list1.get(i) + list2.get(j);
            if (curSum == target) {
                count++;
                i++;
                j--;
            } else if (curSum < target) {
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
}