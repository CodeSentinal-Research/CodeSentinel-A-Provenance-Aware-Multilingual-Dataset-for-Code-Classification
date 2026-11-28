import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public TreeNode buildTree(int[] levelOrder, int[] inorder) {
        if (levelOrder.length == 0 || inorder.length == 0) return null;

        TreeNode root = new TreeNode(levelOrder[0]);
        int idx = -1;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == levelOrder[0]) {
                idx = i;
                break;
            }
        }

        Set<Integer> leftInorder = new HashSet<>();
        for (int i = 0; i < idx; i++) leftInorder.add(inorder[i]);

        List<Integer> leftLevel = new ArrayList<>();
        List<Integer> rightLevel = new ArrayList<>();

        for (int i = 1; i < levelOrder.length; i++) {
            if (leftInorder.contains(levelOrder[i])) {
                leftLevel.add(levelOrder[i]);
            } else {
                rightLevel.add(levelOrder[i]);
            }
        }

        int[] leftLevelArr = leftLevel.stream().mapToInt(i -> i).toArray();
        int[] rightLevelArr = rightLevel.stream().mapToInt(i -> i).toArray();
        int[] leftInorderArr = Arrays.copyOfRange(inorder, 0, idx);
        int[] rightInorderArr = Arrays.copyOfRange(inorder, idx + 1, inorder.length);

        root.left = buildTree(leftLevelArr, leftInorderArr);
        root.right = buildTree(rightLevelArr, rightInorderArr);
        return root;
    }
}