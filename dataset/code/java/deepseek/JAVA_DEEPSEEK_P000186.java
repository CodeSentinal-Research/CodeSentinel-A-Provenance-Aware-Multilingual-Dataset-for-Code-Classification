import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(getMaxLength(nums));
    }

    private static int getMaxLength(int[] nums) {
        int maxLen = 0;
        int positiveProduct = 0;
        int negativeProduct = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                positiveProduct++;
                negativeProduct = negativeProduct > 0 ? negativeProduct - 1 : 0;
            } else if (nums[i] < 0) {
                int temp = positiveProduct;
                positiveProduct = negativeProduct > 0 ? negativeProduct - 1 : 0;
                negativeProduct = temp + 1;
           } else {
                positiveProduct = 0;
                negativeProduct = 0;
            }
            maxLen = Math.max(maxLen, positiveProduct);
        }
        return maxLen;
    }
}
