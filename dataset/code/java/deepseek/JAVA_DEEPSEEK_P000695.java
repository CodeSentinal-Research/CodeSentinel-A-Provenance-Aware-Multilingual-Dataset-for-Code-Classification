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
        System.out.println(firstOccurrence(nums, 0, n - 1, target));
    }

    public static int firstOccurrence(int[] nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            if (mid > 0 && nums[mid - 1] == target) {
                return firstOccurrence(nums, left, mid - 1, target);
            }
            return mid;
        } else if (nums[mid] < target) {
            return firstOccurrence(nums, mid + 1, right, target);
        } else {
            return firstOccurrence(nums, left, mid - 1, target);
        }
    }
}
