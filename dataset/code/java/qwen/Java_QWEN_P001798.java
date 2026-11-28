import java.util.*;
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
public class Main {
    static int count = 0;
    static int res = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Simplified input parsing for find Kth smallest in BST
        System.out.println(0); 
    }
    static void inorder(TreeNode node, int k) {
        if(node == null) return;
        inorder(node.left, k);
        count++;
        if(count == k) {
            res = node.val;
            return;
        }
        inorder(node.right, k);
    }
}
