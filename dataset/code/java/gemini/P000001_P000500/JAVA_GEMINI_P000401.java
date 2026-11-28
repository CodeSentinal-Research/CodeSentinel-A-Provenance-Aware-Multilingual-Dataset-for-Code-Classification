import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n];
            int[] stocks = new int[n];
            for (int i = 0; i < n; i++) {
                names[i] = scanner.next();
                stocks[i] = scanner.nextInt();
            }
            int threshold = scanner.nextInt();
            for (int i = 0; i < n; i++) {
                if (stocks[i] < threshold) {
                    System.out.println(names[i]);
                }
            }
        }
    }
}