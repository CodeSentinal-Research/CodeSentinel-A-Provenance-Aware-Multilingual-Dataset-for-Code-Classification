import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] seq1 = new int[n];
        for(int i=0; i<n; i++) seq1[i] = sc.nextInt();
        int[] seq2 = new int[n];
        for(int i=0; i<n; i++) seq2[i] = sc.nextInt();
        
        TreeNode t1 = buildBST(seq1);
        TreeNode t2 = buildBST(seq2);
        System.out.println(isSameTree(t1, t2) ? "YES" : "NO");
    }
    
    static TreeNode buildBST(int[] arr) {
        if(arr.length == 0) return null;
        TreeNode root = new TreeNode(arr[0]);
        for(int i=1; i<arr.length; i++) insert(root, arr[i]);
        return root;
    }
    
    static void insert(TreeNode node, int val) {
        if(val < node.val) {
            if(node.left == null) node.left = new TreeNode(val);
            else insert(node.left, val);
        } else {
            if(node.right == null) node.right = new TreeNode(val);
            else insert(node.right, val);
        }
    }
    
    static boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) return true;
        if(p == null || q == null) return false;
        return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}
