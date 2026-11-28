import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(findMaxLength(arr));
    }

    public static int findMaxLength(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        int max = 0;
        int runningSum = 0;
        for (int i = 0; i < nums.length; i++) {
            runningSum += (nums[i] == 0) ? -1 : 1;
            if (runningSum == 0) {
                max = Math.max(max, i + 1);
            }
            if (map.containsKey(runningSum)) {
                max = Math.max(max, i - map.get(runningSum));
            } else {
                map.put(runningSum, i);
            }
        }
        return max;
    }
}
