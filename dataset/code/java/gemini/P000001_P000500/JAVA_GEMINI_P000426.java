import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n];
            double[] ratings = new double[n];
            for (int i = 0; i < n; i++) { names[i] = scanner.next(); ratings[i] = scanner.nextDouble(); }
            double thresh = scanner.nextDouble();
            for (int i = 0; i < n; i++) if (ratings[i] >= thresh) System.out.println(names[i]);
        }
    }
}