import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();
        System.out.println(findKthPositive(nums, k));
    }

    public static int findKthPositive(int[] arr, int k) {
        int left = 0, right = arr.length, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] - 1 - mid < k)
                left = mid + 1;
            else
                right = mid;
       }
        return left + k;
    }
}
