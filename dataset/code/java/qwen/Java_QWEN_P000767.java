import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<TreeNode> trees = genTrees(1, n);
        System.out.println(trees.size());
    }
    static List<TreeNode> genTrees(int start, int end) {
        List<TreeNode> list = new ArrayList<>();
        if(start > end) {
            list.add(null);
            return list;
        }
        for(int i=start; i<=end; i++) {
            List<TreeNode> leftTrees = genTrees(start, i-1);
            List<TreeNode> rightTrees = genTrees(i+1, end);
            for(TreeNode l : leftTrees) {
                for(TreeNode r : rightTrees) {
                    TreeNode root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    list.add(root);
                }
            }
        }
        return list;
    }
}
