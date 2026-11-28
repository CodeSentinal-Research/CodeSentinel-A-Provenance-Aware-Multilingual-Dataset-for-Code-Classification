public class Solution {
    public boolean hasOnlyOneChild(int[] preorder) {
        int n = preorder.length;
        for (int i = 0; i < n - 1; i++) {
            int nextDiff = preorder[i] - preorder[i + 1];
            int lastDiff = preorder[i] - preorder[n - 1];
            if ((long)nextDiff * lastDiff < 0) return false;
        }
        return true;
    }
}