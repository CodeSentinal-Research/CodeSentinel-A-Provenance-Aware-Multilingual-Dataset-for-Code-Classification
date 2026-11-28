import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(isSorted(nums, 0));
    }

    public static boolean isSorted(int[] nums, int index) {
        if (index == nums.length - 1) {
            return true;
        }
        if (nums[index] <= nums[index + 1]) {
            return isSorted(nums, index + 1);
       }
        return false;
    }
}
