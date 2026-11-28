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
        scanner.close();
        System.out.println(findLongestHarmoniousSubsequence(nums));
    }

    private static int findLongestHarmoniousSubsequence(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int maxLen = 0;
        for (int num : nums) {
            for (int i = -100; i <= 100; i++) {
                if (map.containsKey(num + i)) {
                    maxLen = Math.max(maxLen, map.get(num + i) + map.get(num) + 1);
                }
            }
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        return maxLen;
    }
}
