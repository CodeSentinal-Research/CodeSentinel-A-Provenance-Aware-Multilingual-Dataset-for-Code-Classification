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
        List<List<TreeNode>> allTrees = generateTrees(1, n);
        System.out.println(allTrees.size());
        // Printing trees omitted for brevity
    }
    
    static List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> list = new ArrayList<>();
        if(start > end) {
            list.add(null);
            return list;
        }
        for(int rootVal=start; rootVal<=end; rootVal++) {
            List<TreeNode> leftTrees = generateTrees(start, rootVal-1);
            List<TreeNode> rightTrees = generateTrees(rootVal+1, end);
            for(TreeNode left : leftTrees) {
                for(TreeNode right : rightTrees) {
                    TreeNode root = new TreeNode(rootVal);
                    root.left = left;
                    root.right = right;
                    list.add(root);
                }
            }
        }
        return list;
    }
}
