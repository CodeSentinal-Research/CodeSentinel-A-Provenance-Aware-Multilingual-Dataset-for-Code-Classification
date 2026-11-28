import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int goal = scanner.nextInt();
        System.out.println(numSubarraysWithSum(nums, goal));
    }

    public static int numSubarraysWithSum(int[] nums, int goal) {
        HashMap<Integer, Integer> count = new HashMap<>();
        int prefixSum = 0;
        int res = 0;
        for (int num : nums) {
            count.put(prefixSum, count.getOrDefault(prefixSum, 0) + 1);
            prefixSum += num;
            if (count.containsKey(prefixSum - goal)) {
                res += count.get(prefixSum - goal);
            }
        }
        return res;
    }
}
