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

        int left = 0;
        int right = n - 1;
        while (left < right) {
            while (left < right && nums[left] != 0) {
                left++;
            }
            while (left < right && nums[right] == 0) {
                right--;
            }
            if (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }

        for (int num : nums) {
            System.out.print(num + " ");
        }
    }
}
