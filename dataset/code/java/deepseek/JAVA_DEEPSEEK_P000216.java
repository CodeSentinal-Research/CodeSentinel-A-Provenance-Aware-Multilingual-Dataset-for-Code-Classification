import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(findShortestSubArray(nums));
    }

    public static int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> left = new HashMap(),
                right = new HashMap(),
                count = new HashMap();

        for (int i = 0; i < nums.length; i++) {
            if (left.get(nums[i]) == null) left.put(nums[i], i);
            right.put(nums[i], i);
            count.put(nums[i], count.getOrDefault(nums[i], 0) + 1);
        }

        int degree = count.values().stream().max(Integer::compare).get();
        int minLength = nums.length;
        for (int x : count.keySet()) {
            if (count.get(x) == degree) {
                minLength = Math.min(minLength, right.get(x) - left.get(x) + 1);
           }
        }

        return minLength;
    }
}
