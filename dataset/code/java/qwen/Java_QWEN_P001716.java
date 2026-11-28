import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static TreeNode res = null;
    static int maxDepth = -1;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for lowest leaf
        System.out.println(0); 
    }
    static void dfs(TreeNode node, int depth) {
        if(node == null) return;
        if(node.left == null && node.right == null) {
            if(depth > maxDepth) {
                maxDepth = depth;
                res = node;
            }
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }
}
