import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = scanner.nextInt();
        }
        int[] finalPrices = finalPrices(prices);
        for (int i = 0; i < n; i++) {
            System.out.print(finalPrices[i] + " ");
        }
    }

    public static int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] stack = new int[n];
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int top = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (top != -1 && prices[stack[top]] > prices[i]) {
                ans[stack[top]] = prices[i];
                top--;
            }
            stack[++top] = i;
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = prices[i];
            }
        }
        return ans;
    }
}
