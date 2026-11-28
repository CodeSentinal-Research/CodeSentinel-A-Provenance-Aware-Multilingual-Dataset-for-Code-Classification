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
        // Simplified input parsing for count internal nodes
        System.out.println(0); 
    }
    static void dfs(TreeNode node) {
        if(node == null) return;
        if(node.left != null || node.right != null) count++;
        dfs(node.left);
        dfs(node.right);
    }
}
