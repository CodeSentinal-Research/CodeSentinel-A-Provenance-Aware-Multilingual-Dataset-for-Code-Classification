import java.util.Scanner;
public class Solution {
    static class TreeNode{int val;TreeNode left,right;TreeNode(int v){val=v;}}
    public TreeNode insert(TreeNode root,int v){if(root==null)return new TreeNode(v);if(v<root.val)root.left=insert(root.left,v);else root.right=insert(root.right,v);return root;}
    public int height(TreeNode root){if(root==null)return 0;return 1+Math.max(height(root.left),height(root.right));}
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); TreeNode root=null; Solution sol=new Solution();
        for(int i=0;i<n;i++) root=sol.insert(root,sc.nextInt());
        System.out.println(sol.height(root));
    }
}
