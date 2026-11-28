import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(findMax(nums, 0, n - 1));
    }

    private static int findMax(int[] nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        int mid = (start + end) / 2;
        int max1 = findMax(nums, start, mid);
        int max2 = findMax(nums, mid + 1, end);
        return Math.max(max1, max2);
    }
}
