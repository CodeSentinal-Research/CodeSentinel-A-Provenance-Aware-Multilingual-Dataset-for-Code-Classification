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
        int buy = prices[0], sell = 0, cool = 0;

        for (int i = 1; i < n; i++) {
            int temp = buy;
            buy = Math.max(buy, cool - prices[i]);
            cool = Math.max(cool, sell);
            sell = Math.max(sell, temp + prices[i] - prices[i - 1]);
        }

        return Math.max(sell, cool);
    }
}
