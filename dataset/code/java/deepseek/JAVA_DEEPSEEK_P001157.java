import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();
        int[] prices = new int[length];
        for (int i = 0; i < length; i++) {
            prices[i] = scanner.nextInt();
        }
        System.out.println(maxRevenue(prices));
    }

    private static int maxRevenue(int[] prices) {
        int[] revenue = new int[prices.length + 1];
        revenue[0] = 0;
        for (int i = 1; i <= prices.length; i++) {
            int maxPrice = Integer.MIN_VALUE;
            for (int j = 0; j < i; j++) {
                maxPrice = Math.max(maxPrice, prices[j] + revenue[i - j - 1]);
            }
            revenue[i] = maxPrice;
       }
        return revenue[prices.length];
    }
}
