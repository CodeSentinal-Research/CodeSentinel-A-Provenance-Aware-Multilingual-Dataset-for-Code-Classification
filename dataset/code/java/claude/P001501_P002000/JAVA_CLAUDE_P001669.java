import java.util.Scanner;
public class Solution {
    static class TreeNode{int val;TreeNode left,right;TreeNode(int v){val=v;}}
    public TreeNode insert(TreeNode root,int v){if(root==null)return new TreeNode(v);if(v<root.val)root.left=insert(root.left,v);else root.right=insert(root.right,v);return root;}
    public void preorder(TreeNode root,StringBuilder sb){if(root==null)return;sb.append(root.val).append(" ");preorder(root.left,sb);preorder(root.right,sb);}
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); TreeNode root=null; Solution sol=new Solution();
        for(int i=0;i<n;i++) root=sol.insert(root,sc.nextInt());
        StringBuilder sb=new StringBuilder(); sol.preorder(root,sb);
        System.out.println(sb.toString().trim());
    }
}
