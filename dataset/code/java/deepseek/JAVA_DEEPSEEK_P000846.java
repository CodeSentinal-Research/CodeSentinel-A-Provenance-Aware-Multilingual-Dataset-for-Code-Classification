import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] quantities = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            quantities[i] = Integer.parseInt(st.nextToken());
        }
        pw.println(minimizedMaximum(n, m, quantities));
        pw.close();
    }

    static int minimizedMaximum(int n, int m, int[] quantities) {
        int low = 1, high = 100000;
        while (low < high) {
            int mid = (low + high) / 2;
            if (canDistribute(n, m, quantities, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }

    static boolean canDistribute(int n, int m, int[] quantities, int mid) {
        int total = 0;
        for (int i = 0; i < m; i++) {
            total += quantities[i] / mid;
            if (quantities[i] % mid != 0) {
                total++;
            }
        }
        return total <= n;
    }
}
