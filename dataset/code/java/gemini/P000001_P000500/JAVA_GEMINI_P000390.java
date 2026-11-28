import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n];
            double[] prices = new double[n];
            for (int i = 0; i < n; i++) {
                names[i] = scanner.next();
                prices[i] = scanner.nextDouble();
            }
            double minP = scanner.nextDouble();
            double maxP = scanner.nextDouble();
            for (int i = 0; i < n; i++) {
                if (prices[i] >= minP && prices[i] <= maxP) {
                    System.out.println(names[i]);
                }
            }
        }
    }
}