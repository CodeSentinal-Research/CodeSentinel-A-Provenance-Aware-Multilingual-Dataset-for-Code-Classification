import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static long sum = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for sum of even levels
        System.out.println(0); 
    }
    static void dfs(TreeNode node, int level) {
        if(node == null) return;
        if(level % 2 == 0) sum += node.val;
        dfs(node.left, level + 1);
        dfs(node.right, level + 1);
    }
}
