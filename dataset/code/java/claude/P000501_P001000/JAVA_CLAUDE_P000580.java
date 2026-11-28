import java.util.Scanner;
public class Solution {
    static class ListNode{int val;ListNode next;ListNode(int v){val=v;}}
    public ListNode middleNode(ListNode head){
        ListNode slow=head,fast=head;
        while(fast!=null&&fast.next!=null){slow=slow.next;fast=fast.next.next;}
        return slow;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); ListNode h=null,t=null;
        for(int i=0;i<n;i++){ListNode nd=new ListNode(sc.nextInt());if(h==null)h=t=nd;else{t.next=nd;t=nd;}}
        System.out.println(new Solution().middleNode(h).val);
    }
}
