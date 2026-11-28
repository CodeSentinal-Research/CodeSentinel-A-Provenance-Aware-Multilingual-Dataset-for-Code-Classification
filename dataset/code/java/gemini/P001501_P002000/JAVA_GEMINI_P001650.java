import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int postIdx;
    private Map<Integer, Integer> inMap = new HashMap<>();

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        postIdx = postorder.length - 1;
        inMap.clear();
        for (int i = 0; i < inorder.length; i++) inMap.put(inorder[i], i);
        return build(postorder, 0, inorder.length - 1);
    }

    private TreeNode build(int[] postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return null;
        int val = postorder[postIdx--];
        TreeNode root = new TreeNode(val);
        int mid = inMap.get(val);

        root.right = build(postorder, mid + 1, inEnd);
        root.left = build(postorder, inStart, mid - 1);
        return root;
    }
}