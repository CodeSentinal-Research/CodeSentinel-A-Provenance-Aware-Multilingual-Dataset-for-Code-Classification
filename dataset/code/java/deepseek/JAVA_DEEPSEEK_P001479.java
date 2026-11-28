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
        System.out.println(findUnsortedSubarray(nums));
    }

    public static int findUnsortedSubarray(int[] nums) {
        int n = nums.length;
        int start = -1, end = -2;
        int max = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < max) {
                end = i;
            } else {
                max = nums[i];
            }
        }
        if (end == -2) return 0;
        int min = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > min) {
                start = i;
            } else {
                min = nums[i];
            }
        }
        return end - start + 1;
    }
}
