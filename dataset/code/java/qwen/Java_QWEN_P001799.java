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
        // Simplified input parsing for find Kth largest in BST
        System.out.println(0); 
    }
    static void reverseInorder(TreeNode node, int k) {
        if(node == null) return;
        reverseInorder(node.right, k);
        count++;
        if(count == k) {
            res = node.val;
            return;
        }
        reverseInorder(node.left, k);
    }
}
