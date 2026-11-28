import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();

        long maxProduct = Long.MIN_VALUE;
        long minProduct = Long.MAX_VALUE;
        long maxProductEndingHere = 1;
        long minProductEndingHere = 1;

        for (int num : nums) {
            if (num < 0) {
                long temp = maxProduct;
                maxProduct = minProduct;
                minProduct = temp;
            }

            maxProductEndingHere = Math.max(num, maxProductEndingHere * num);
            minProductEndingHere = Math.min(num, minProductEndingHere * num);

            maxProduct = Math.max(maxProduct, maxProductEndingHere);
            minProduct = Math.min(minProduct, minProductEndingHere);
        }

        System.out.println(maxProduct);
    }
}
