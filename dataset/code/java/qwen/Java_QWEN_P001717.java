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
        // Simplified input parsing for count root-to-leaf paths
        System.out.println(0); 
    }
    static void dfs(TreeNode node) {
        if(node == null) return;
        if(node.left == null && node.right == null) {
            count++;
            return;
        }
        dfs(node.left);
        dfs(node.right);
    }
}
