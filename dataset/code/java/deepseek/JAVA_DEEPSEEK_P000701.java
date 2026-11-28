import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(findMin(nums, 0, n - 1));
    }

    public static int findMin(int[] nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        int mid = (start + end) / 2;
        if (nums[mid] > nums[end]) {
            return findMin(nums, mid + 1, end);
       } else {
            return findMin(nums, start, mid);
        }
    }
}
