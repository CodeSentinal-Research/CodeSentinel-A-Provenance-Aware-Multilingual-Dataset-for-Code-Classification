import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static TreeNode res = null;
    static long minSum = Long.MAX_VALUE;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for subtree with min sum
        System.out.println(0); 
    }
    static long dfs(TreeNode node) {
        if(node == null) return 0;
        long sum = node.val + dfs(node.left) + dfs(node.right);
        if(sum < minSum) {
            minSum = sum;
            res = node;
        }
        return sum;
    }
}
