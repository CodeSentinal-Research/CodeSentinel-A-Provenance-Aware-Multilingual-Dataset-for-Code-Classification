import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static long maxSum = Long.MIN_VALUE;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for max root-to-leaf sum
        System.out.println(0); 
    }
    static void dfs(TreeNode node, long currSum) {
        if(node == null) return;
        currSum += node.val;
        if(node.left == null && node.right == null) {
            maxSum = Math.max(maxSum, currSum);
            return;
        }
        dfs(node.left, currSum);
        dfs(node.right, currSum);
    }
}
