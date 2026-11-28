import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(countSubarrays(nums, k));
    }

    public static long countSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] count = new int[n + 1];
        int[] distinctCount = new int[n + 1];
        Arrays.fill(count, 1);
        Arrays.fill(distinctCount, 1);
        for (int i = 0; i < n; i++) {
            if (distinctCount[nums[i]] == 1) {
                distinctCount[nums[i]]++;
            } else {
                count[nums[i]] += count[nums[i] - 1];
                count[nums[i] - 1] = 0;
            }
        }
        long result = 0;
        for (int i = 0; i < n; i++) {
            if (distinctCount[nums[i]] <= k) {
                result += count[nums[i]];
            }
        }
        return result;
    }
}
