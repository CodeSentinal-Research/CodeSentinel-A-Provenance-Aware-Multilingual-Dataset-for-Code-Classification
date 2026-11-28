import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt();
            Integer[] x = new Integer[m - 1];
            for (int i = 0; i < m - 1; i++) x[i] = sc.nextInt();
            Integer[] y = new Integer[n - 1];
            for (int j = 0; j < n - 1; j++) y[j] = sc.nextInt();

            Arrays.sort(x, Collections.reverseOrder());
            Arrays.sort(y, Collections.reverseOrder());

            long hPieces = 1, vPieces = 1, totalCost = 0;
            int i = 0, j = 0;

            while (i < x.length && j < y.length) {
                if (x[i] >= y[j]) {
                    totalCost += (long) x[i] * vPieces;
                    hPieces++;
                    i++;
                } else {
                    totalCost += (long) y[j] * hPieces;
                    vPieces++;
                    j++;
                }
            }
            while (i < x.length) {
                totalCost += (long) x[i] * vPieces;
                i++;
            }
            while (j < y.length) {
                totalCost += (long) y[j] * hPieces;
                j++;
            }

            System.out.println(totalCost);
        }
        sc.close();
    }
}