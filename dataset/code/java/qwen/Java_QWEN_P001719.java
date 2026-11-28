import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static List<Integer> path = new ArrayList<>();
    static List<Integer> longest = new ArrayList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for longest root-to-leaf path
        System.out.println(""); 
    }
    static void dfs(TreeNode node) {
        if(node == null) return;
        path.add(node.val);
        if(node.left == null && node.right == null) {
            if(path.size() > longest.size()) {
                longest = new ArrayList<>(path);
            }
        }
        dfs(node.left);
        dfs(node.right);
        path.remove(path.size() - 1);
    }
}
