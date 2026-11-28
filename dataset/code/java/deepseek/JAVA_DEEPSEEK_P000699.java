import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        reverseArray(nums, 0, n - 1);
        for (int num : nums) {
            System.out.print(num + " ");
        }
    }

    public static void reverseArray(int[] nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        reverseArray(nums, start + 1, end - 1);
    }
}
