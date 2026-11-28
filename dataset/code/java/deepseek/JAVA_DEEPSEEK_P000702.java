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
        System.out.println(countOccurrences(nums, target));
    }

    public static int countOccurrences(int[] nums, int target) {
        return countOccurrencesHelper(nums, target, 0, nums.length - 1);
    }

    private static int countOccurrencesHelper(int[] nums, int target, int start, int end) {
        if (start > end) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            int left = countOccurrencesHelper(nums, target, start, mid - 1);
            int right = countOccurrencesHelper(nums, target, mid + 1, end);
            return left + right + 1;
       } else if (nums[mid] < target) {
            return countOccurrencesHelper(nums, target, mid + 1, end);
        } else {
            return countOccurrencesHelper(nums, target, start, mid - 1);
        }
    }
}
