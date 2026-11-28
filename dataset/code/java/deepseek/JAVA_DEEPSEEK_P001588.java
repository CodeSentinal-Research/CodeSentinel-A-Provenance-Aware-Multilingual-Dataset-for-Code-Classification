import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(countOdds(nums, K));
    }

    private static int countOdds(int[] nums, int K) {
        int count = 0;
        int oddCount = 0;
        int start = 0;
        for (int end = 0; end < nums.length; end++) {
            if (nums[end] % 2 == 1) {
                oddCount++;
            }
            if (oddCount == K) {
                count++;
                oddCount = 0;
                start = end + 1;
            }
        }
        return count;
    }
}
