import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n];
            double[] sals = new double[n];
            for (int i = 0; i < n; i++) {
                names[i] = scanner.next();
                sals[i] = scanner.nextDouble();
            }
            double minSal = scanner.nextDouble();
            double maxSal = scanner.nextDouble();
            for (int i = 0; i < n; i++) {
                if (sals[i] >= minSal && sals[i] <= maxSal) {
                    System.out.println(names[i]);
                }
            }
        }
    }
}