import java.util.Scanner;
public class Solution {
    static class ListNode{int val;ListNode next;ListNode(int v){val=v;}}
    public ListNode insert(ListNode head,int val){
        ListNode nd=new ListNode(val);
        if(head==null)return nd;
        ListNode cur=head; while(cur.next!=null)cur=cur.next; cur.next=nd; return head;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); ListNode head=null;
        Solution sol=new Solution();
        for(int i=0;i<n;i++) head=sol.insert(head,sc.nextInt());
        StringBuilder sb=new StringBuilder();
        while(head!=null){sb.append(head.val);if(head.next!=null)sb.append(" -> ");head=head.next;}
        System.out.println(sb);
    }
}
