import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int target = scanner.nextInt();
        System.out.println(linearSearch(nums, target, 0));
    }

    public static boolean linearSearch(int[] nums, int target, int index) {
        if (index == nums.length) {
            return false;
        }
        if (nums[index] == target) {
            return true;
        }
        return linearSearch(nums, target, index + 1);
    }
}
