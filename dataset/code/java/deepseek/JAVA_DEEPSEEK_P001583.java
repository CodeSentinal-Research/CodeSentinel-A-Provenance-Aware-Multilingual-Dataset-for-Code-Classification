import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(countSubarrays(nums, K));
    }

    public static long countSubarrays(int[] nums, int K) {
        int n = nums.length;
        int[] count = new int[n + 1];
        int[] distinct = new int[n + 1];
        Arrays.fill(count, 1);
        Arrays.fill(distinct, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                distinct[i] = distinct[i - 1] + 1;
            } else {
                distinct[i] = distinct[i - 1];
            }
            count[i] = distinct[i] * count[i - 1];
        }
        long total = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != nums[i + 1]) {
                total += count[i] * count[n - i - 1];
            }
        }
        return total;
    }
}
