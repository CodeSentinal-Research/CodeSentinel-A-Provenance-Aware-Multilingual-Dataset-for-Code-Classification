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
        System.out.println(findLast(nums, target, 0, n - 1));
    }

    public static int findLast(int[] nums, int target, int start, int end) {
        if (start > end) {
            return -1;
        }
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            if (mid == nums.length - 1 || nums[mid + 1] != target) {
                return mid;
           }
            return findLast(nums, target, mid + 1, end);
        } else if (nums[mid] > target) {
            return findLast(nums, target, start, mid - 1);
        } else {
            return findLast(nums, target, mid + 1, end);
        }
    }
}
