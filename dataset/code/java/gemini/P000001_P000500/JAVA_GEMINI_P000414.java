import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n], statuses = new String[n];
            double[] prices = new double[n];
            for (int i = 0; i < n; i++) { names[i] = scanner.next(); prices[i] = scanner.nextDouble(); statuses[i] = scanner.next(); }
            double budget = scanner.nextDouble();
            for (int i = 0; i < n; i++) {
                String st = statuses[i].toLowerCase();
                if (prices[i] <= budget && (st.equals("available") || st.equals("true") || st.equals("1") || st.equals("yes"))) {
                    System.out.println(names[i]);
                }
            }
        }
    }
}