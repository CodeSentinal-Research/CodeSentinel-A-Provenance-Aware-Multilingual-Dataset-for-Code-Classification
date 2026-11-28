import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(maxLength(nums));
    }

    public static int maxLength(int[] nums) {
        int maxLength = 0;
        Map<Integer, Integer> prefixSumMap = new HashMap<>();
        int prefixSum = 0;
        for (int num : nums) {
            prefixSum += num % 2 == 0 ? 1 : -1;
            if (prefixSum == 0) {
                maxLength = Math.max(maxLength, 1);
            } else if (prefixSumMap.containsKey(prefixSum - 1)) {
                maxLength = Math.max(maxLength, prefixSumMap.get(prefixSum - 1) + 1);
           }
        }
        return maxLength;
    }
}
