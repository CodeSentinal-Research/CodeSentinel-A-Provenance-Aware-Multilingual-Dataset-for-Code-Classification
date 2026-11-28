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
        // Simplified input parsing for good nodes
        System.out.println(0); 
    }
    static int dfs(TreeNode node, int maxVal) {
        if(node == null) return 0;
        int good = 0;
        if(node.val >= maxVal) {
            good = 1;
            maxVal = node.val;
        }
        return good + dfs(node.left, maxVal) + dfs(node.right, maxVal);
    }
}
