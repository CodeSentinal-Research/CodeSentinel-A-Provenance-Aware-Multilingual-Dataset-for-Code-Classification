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

    public int[] findClosestPair(TreeNode root1, TreeNode root2, int target) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        inorder(root1, list1);
        inorder(root2, list2);

        int i = 0, j = list2.size() - 1;
        long bestDiff = Long.MAX_VALUE;
        int[] res = new int[]{list1.get(0), list2.get(list2.size() - 1)};

        while (i < list1.size() && j >= 0) {
            int curSum = list1.get(i) + list2.get(j);
            long diff = Math.abs((long)curSum - target);
            if (diff < bestDiff) {
                bestDiff = diff;
                res = new int[]{list1.get(i), list2.get(j)};
            }
            if (curSum < target) i++;
            else j--;
        }
        return res;
    }
}