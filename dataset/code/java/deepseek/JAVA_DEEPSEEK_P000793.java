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
        System.out.println(numberOfSubarrays(nums, k));
    }

    public static int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        int[] count = new int[n + 1];
        int oddNumbers = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) {
                oddNumbers++;
                prefix[oddNumbers] = i + 1;
            }
            if (oddNumbers >= k) {
                count[oddNumbers - k]++;
            }
            if (oddNumbers >= k - 1) {
                result += count[oddNumbers - k + 1];
            }
        }
        return result;
    }
}
