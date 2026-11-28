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
        System.out.println(longestWave(nums));
    }

    private static int longestWave(int[] nums) {
        int n = nums.length;
        int maxLength = 1;
        int currLength = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currLength++;
            } else {
                maxLength = Math.max(maxLength, currLength);
                currLength = 1;
            }
        }
        maxLength = Math.max(maxLength, currLength);
        return maxLength;
    }
}
