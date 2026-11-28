import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(findLongestWiggleSequence(nums));
    }

    private static int findLongestWiggleSequence(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int n = nums.length;
        int[] up = new int[n];
        int[] down = new int[n];

        up[0] = 1;
        down[0] = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = Math.max(up[i], down[i - 1] + 1);
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = Math.max(down[i], up[i - 1] + 1);
                up[i] = up[i - 1];
            } else {
                down[i] = up[i] = down[i - 1] = up[i - 1] = 0;
            }
        }

        return Math.max(Math.max(down[n - 1], up[n - 1]), Math.max(down[n - 2], up[n - 2]));
    }
}
