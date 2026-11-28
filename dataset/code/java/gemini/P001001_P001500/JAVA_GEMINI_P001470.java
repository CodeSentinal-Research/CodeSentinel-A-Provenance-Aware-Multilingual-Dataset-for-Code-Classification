import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[] a = new int[n];
            int[] b = new int[m];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            for (int j = 0; j < m; j++) b[j] = sc.nextInt();

            int i = n - 1, j = 0;
            while (i >= 0 && j < m) {
                if (a[i] > b[j]) {
                    int tmp = a[i]; a[i] = b[j]; b[j] = tmp;
                    i--; j++;
                } else {
                    break;
                }
            }
            Arrays.sort(a);
            Arrays.sort(b);

            for (int val : a) System.out.print(val + " ");
            for (int val : b) System.out.print(val + " ");
            System.out.println();
        }
        sc.close();
    }
}