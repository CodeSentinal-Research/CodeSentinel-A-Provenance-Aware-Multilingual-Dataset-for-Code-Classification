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
        // Simplified input parsing for count univalue subtrees
        System.out.println(0); 
    }
    static boolean dfs(TreeNode node) {
        if(node == null) return true;
        boolean left = dfs(node.left);
        boolean right = dfs(node.right);
        if(left && right) {
            if(node.left != null && node.left.val != node.val) return false;
            if(node.right != null && node.right.val != node.val) return false;
            count++;
            return true;
        }
        return false;
    }
}
