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

    public static int countSubarrays(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int count = 0, prefixSum = 0;
        map.put(0, 1);
        for (int num : nums) {
            prefixSum += num == 0 ? -1 : 1;
            if (map.containsKey(prefixSum)) {
                count += map.get(prefixSum);
                map.put(prefixSum, map.get(prefixSum) + 1);
            } else {
                map.put(prefixSum, 1);
           }
        }
        return count;
    }
}
