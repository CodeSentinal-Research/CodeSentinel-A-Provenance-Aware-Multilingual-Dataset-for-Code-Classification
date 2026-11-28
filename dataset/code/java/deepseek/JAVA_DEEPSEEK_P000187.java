import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(firstMissingPositive(nums));
    }

    public static int firstMissingPositive(int[] nums) {
        int n = nums.length;

        // Mark 1 as seen
        if (n == 0) {
            return 1;
        }

        // Mark negatives and zeros as seen
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = Integer.MAX_VALUE;
            }
       
           // Mark numbers larger than n as seen
           if (nums[i] > n) {
               nums[i] = Integer.MAX_VALUE;
           }
        }

        // For each number in the array, mark its corresponding index as seen
        for (int i = 0; i < n; i++) {
           int num = Math.abs(nums[i]);
           if (num == Integer.MAX_VALUE) {
               continue;
           }
           num--;
           if (nums[num] > 0) {
               nums[num] = -nums[num];
           }
        }

        // Find the first unseen number
        for (int i = 0; i < n; i++) {
           if (nums[i] >= 0) {
               return i + 1;
           }
        }

        // If all numbers are seen, the smallest missing positive is n + 1
        return n + 1;
    }
}
