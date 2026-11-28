import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        generateSubsequences(nums, 0, "");
    }

    private static void generateSubsequences(int[] nums, int index, String subsequence) {
        if (index == nums.length) {
            System.out.println(subsequence);
            return;
        }
        generateSubsequences(nums, index + 1, subsequence);
        generateSubsequences(nums, index + 1, subsequence + nums[index] + " ");
    }
}
