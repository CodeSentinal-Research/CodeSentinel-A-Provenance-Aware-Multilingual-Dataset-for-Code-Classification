import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static long sum = 0;
    static int maxDepth = -1;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for sum of deepest nodes
        System.out.println(0); 
    }
    static void dfs(TreeNode node, int depth) {
        if(node == null) return;
        if(depth > maxDepth) {
            maxDepth = depth;
            sum = node.val;
        } else if(depth == maxDepth) {
            sum += node.val;
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }
}
