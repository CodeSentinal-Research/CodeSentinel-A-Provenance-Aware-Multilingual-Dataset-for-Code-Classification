import java.util.*;
public class Solution {
    static class TreeNode{int val;TreeNode left,right;TreeNode(int v){val=v;}}
    public TreeNode insert(TreeNode root,int v){if(root==null)return new TreeNode(v);if(v<root.val)root.left=insert(root.left,v);else root.right=insert(root.right,v);return root;}
    public void levelOrder(TreeNode root){
        if(root==null)return; Queue<TreeNode> q=new LinkedList<>(); q.offer(root);
        StringBuilder sb=new StringBuilder();
        while(!q.isEmpty()){TreeNode cur=q.poll();sb.append(cur.val).append(" ");if(cur.left!=null)q.offer(cur.left);if(cur.right!=null)q.offer(cur.right);}
        System.out.println(sb.toString().trim());
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); TreeNode root=null; Solution sol=new Solution();
        for(int i=0;i<n;i++) root=sol.insert(root,sc.nextInt());
        sol.levelOrder(root);
    }
}
