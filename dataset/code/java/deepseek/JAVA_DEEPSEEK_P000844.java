import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();
        System.out.println(maxTastiness(prices, k));
    }

    public static int maxTastiness(int[] prices, int k) {
        Arrays.sort(prices);
        int left = 0;
        int right = prices[prices.length - 1] - prices[0];
        while (left < right) {
            int mid = (right + left + 1) / 2;
            if (canPick(prices, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    public static boolean canPick(int[] prices, int k, int tastiness) {
        int count = 1;
        int min = prices[0];
        for (int price : prices) {
            if (price - min > tastiness) {
                count++;
                min = price;
                if (count == k) {
                    return true;
                }
            }
        }
        return false;
    }
}
