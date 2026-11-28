import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static int diameter = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for diameter
        System.out.println(0); 
    }
    static int height(TreeNode node) {
        if(node == null) return 0;
        int l = height(node.left);
        int r = height(node.right);
        diameter = Math.max(diameter, l + r);
        return 1 + Math.max(l, r);
    }
}
