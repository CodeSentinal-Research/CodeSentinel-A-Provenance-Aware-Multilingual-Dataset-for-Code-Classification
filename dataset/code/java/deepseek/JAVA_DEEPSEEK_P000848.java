import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextLong();
        }
        System.out.println(minMaxArray(nums));
    }

    public static long minMaxArray(long[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        long avg = sum / n;
        long res = nums[0];
        for (int i = 1; i < n; i++) {
            res = Math.max(res, (sum - nums[i] + avg) / i);
        }
        return res;
    }
}
