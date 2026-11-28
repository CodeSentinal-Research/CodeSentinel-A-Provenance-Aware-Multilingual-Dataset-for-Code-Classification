import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n];
            double[] gpas = new double[n], incs = new double[n];
            for (int i = 0; i < n; i++) { names[i] = scanner.next(); gpas[i] = scanner.nextDouble(); incs[i] = scanner.nextDouble(); }
            double minGpa = scanner.nextDouble(), maxInc = scanner.nextDouble();
            for (int i = 0; i < n; i++) {
                if (gpas[i] >= minGpa && incs[i] <= maxInc) System.out.println(names[i]);
            }
        }
    }
}