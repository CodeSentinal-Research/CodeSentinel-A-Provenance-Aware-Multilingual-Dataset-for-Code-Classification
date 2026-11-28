import java.util.*;
class ShortestSubarraySumAtLeastK{
  static int shortestSubarray(int [] nums,int k){
    int n = nums.length;
    long[] prefix = new long[n+1];
    for(int i=0;i<n;i++){
      prefix[i+1] = prefix[i] + nums[i];
    }
    int min = n+1;
    Deque<Integer> dq = new ArrayDeque<>();
    for(int i=0;i<=n;i++){
      while(!dq.isEmpty() && prefix[i]-prefix[dq.peekFirst()]>=k){
        min = Math.min(min,i-dq.pollFirst());
      }
      while(!dq.isEmpty() && prefix[i]<=prefix[dq.peekLast()]){
        dq.pollLast();
      }
      dq.addLast(i);
    }
    return min <=n ? min : -1;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int nums[] = new int[n];
    for(int i=0;i<n;i++){
      nums[i] = sc.nextInt();
    }
    int k = sc.nextInt();
    System.out.println(shortestSubarray(nums, k));
    sc.close();
  }
}