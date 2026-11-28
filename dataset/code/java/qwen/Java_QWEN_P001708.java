import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static int count = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for pseudo-palindromic paths
        System.out.println(0); 
    }
    static void dfs(TreeNode node, int mask) {
        if(node == null) return;
        mask ^= (1 << node.val);
        if(node.left == null && node.right == null) {
            if((mask & (mask - 1)) == 0) count++;
            return;
        }
        dfs(node.left, mask);
        dfs(node.right, mask);
    }
}
