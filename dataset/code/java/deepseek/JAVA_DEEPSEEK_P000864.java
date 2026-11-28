import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(findMissingNumber(n, nums));
    }

    private static int findMissingNumber(int n, int[] nums) {
        int xor = 0;
        for (int i = 1; i <= n+1; i++) {
            xor ^= i;
       }
        for (int num : nums) {
            xor ^= num;
        }
        return xor;
    }
}
