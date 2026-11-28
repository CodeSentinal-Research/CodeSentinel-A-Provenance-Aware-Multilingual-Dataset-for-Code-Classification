import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = br.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        String[] numsStr = br.readLine().split(" ");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
        }
        System.out.println(shortestSubarray(nums, k));
    }

    public static int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        Deque<Integer> queue = new ArrayDeque<>();
        int minLen = n + 1;
        for (int i = 0; i <= n; i++) {
            while (!queue.isEmpty() && prefixSum[i] - prefixSum[queue.peekFirst()] >= k) {
                minLen = Math.min(minLen, i - queue.pollFirst());
            }
            while (!queue.isEmpty() && prefixSum[i] <= prefixSum[queue.peekLast()]) {
                queue.pollLast();
           }
            queue.offerLast(i);
        }
        return minLen <= n ? minLen : -1;
    }
}
