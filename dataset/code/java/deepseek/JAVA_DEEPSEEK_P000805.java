import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(countSubarrays(nums));
    }

    private static long countSubarrays(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int prefixSum = 0;
        long count = 0;
        map.put(0, 1);
        for (int num : nums) {
            prefixSum += num < 0 ? -1 : 1;
            if (map.containsKey(prefixSum - 1)) {
                count += map.get(prefixSum - 1);
            }
            map.put(prefixSum, map.getOrDefault(prefixSum, 0) + 1);
        }
        return count;
    }
}
