import java.util.Scanner;
public class Solution {
    static class ListNode{int val;ListNode next;ListNode(int v){val=v;}}
    public boolean hasCycle(ListNode head){
        ListNode slow=head,fast=head;
        while(fast!=null&&fast.next!=null){slow=slow.next;fast=fast.next.next;if(slow==fast)return true;}
        return false;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(),cp=sc.nextInt();
        ListNode[] nodes=new ListNode[n]; ListNode head=null;
        for(int i=0;i<n;i++){nodes[i]=new ListNode(sc.nextInt());if(i>0)nodes[i-1].next=nodes[i];if(i==0)head=nodes[0];}
        if(cp>=0)nodes[n-1].next=nodes[cp];
        System.out.println(new Solution().hasCycle(head)?"Cycle Detected":"No Cycle");
    }
}
