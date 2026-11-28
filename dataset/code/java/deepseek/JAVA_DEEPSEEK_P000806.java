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
        System.out.println(findMaxLength(nums));
    }

    public static int findMaxLength(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        int max = 0;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 0) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                max = Math.max(max, i + 1);
            } else if (map.containsKey(count)) {
                max = Math.max(max, i - map.get(count));
           } else {
                map.put(count, i);
            }
        }
        return max;
    }
}
