import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int preIdx = 0;
    private Map<Integer, Integer> postMap = new HashMap<>();

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        preIdx = 0;
        postMap.clear();
        for (int i = 0; i < postorder.length; i++) postMap.put(postorder[i], i);
        return build(preorder, 0, postorder.length - 1);
    }

    private TreeNode build(int[] preorder, int postStart, int postEnd) {
        if (postStart > postEnd || preIdx >= preorder.length) return null;
        TreeNode root = new TreeNode(preorder[preIdx++]);

        if (postStart == postEnd || preIdx >= preorder.length) return root;

        int nextVal = preorder[preIdx];
        if (!postMap.containsKey(nextVal) || postMap.get(nextVal) > postEnd) return root;

        int mid = postMap.get(nextVal);
        root.left = build(preorder, postStart, mid);
        root.right = build(preorder, mid + 1, postEnd - 1);
        return root;
    }
}