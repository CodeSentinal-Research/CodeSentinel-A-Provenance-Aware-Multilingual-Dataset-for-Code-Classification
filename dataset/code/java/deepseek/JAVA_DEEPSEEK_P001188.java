import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = scanner.nextInt();
        }
        System.out.println(maxProfit(prices));
    }

    public static int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }

        int n = prices.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int min = prices[0];
        int max = 0;

        // calculate max profit for left transaction
        for (int i = 1; i < n; i++) {
            min = Math.min(min, prices[i]);
            left[i] = Math.max(left[i - 1], prices[i] - min);
        }

        // calculate max profit for right transaction
        int maxRight = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxRight = Math.max(maxRight, prices[i]);
            right[i] = Math.max(right[i + 1], maxRight - prices[i]);
        }

        // calculate max profit for buying and selling at the same time
        int profit = 0;
        for (int i = 0; i < n; i++) {
            profit = Math.max(profit, left[i] + right[i]);
        }

        return profit;
    }
}
