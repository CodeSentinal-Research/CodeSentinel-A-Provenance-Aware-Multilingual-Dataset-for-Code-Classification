import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] numsStr = br.readLine().split(" ");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
        }
        List<Integer> res = largestDivisibleSubset(nums);
        for (int num : res) {
            System.out.print(num + " ");
        }
    }

    public static List<Integer> largestDivisibleSubset(int[] nums) {
        if (nums == null || nums.length == 0) {
            return new ArrayList<>();
        }
        Arrays.sort(nums);
        int n = nums.length;
        int[] dp = new int[n];
        int[] prev = new int[n];
        int max = 1;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            prev[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > max) {
                max = dp[i];
                idx = i;
            }
        }
        List<Integer> res = new ArrayList<>();
        while (res.size() < max) {
            res.add(0, nums[idx]);
            idx = prev[idx];
        }
        return res;
    }
}
