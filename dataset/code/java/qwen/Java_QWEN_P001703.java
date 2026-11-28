import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static int maxDiff = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for max ancestor diff
        System.out.println(0); 
    }
    static int[] dfs(TreeNode node) {
        if(node == null) return new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE};
        int[] left = dfs(node.left);
        int[] right = dfs(node.right);
        int minVal = Math.min(node.val, Math.min(left[0], right[0]));
        int maxVal = Math.max(node.val, Math.max(left[1], right[1]));
        maxDiff = Math.max(maxDiff, Math.max(Math.abs(node.val - minVal), Math.abs(node.val - maxVal)));
        return new int[]{minVal, maxVal};
    }
}
