import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        long[] batteries = new long[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            batteries[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(batteries);
        long left = 1, right = batteries[m - 1] * n;
        while (left < right) {
            long mid = (right - left) / 2 + left;
            if (check(batteries, mid, n)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        pw.println(left - 1);
        pw.close();
    }

    private static boolean check(long[] batteries, long mid, int n) {
        long sum = 0;
        for (int i = 0; i < batteries.length; i++) {
            sum += mid / batteries[i];
        }
        return sum >= n;
    }
}
