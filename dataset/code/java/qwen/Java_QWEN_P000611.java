import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        int maxSum = 0;
        for(int i=0; i<n/2; i++) {
            maxSum = Math.max(maxSum, arr[i] + arr[n-1-i]);
        }
        System.out.println(maxSum);
    }
}
