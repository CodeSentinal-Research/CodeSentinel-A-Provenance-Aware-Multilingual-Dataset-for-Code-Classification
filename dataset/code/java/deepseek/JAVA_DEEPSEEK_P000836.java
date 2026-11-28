import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] position = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            position[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(position);
        int low = 0, high = position[n - 1] - position[0] + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (check(position, mid, m)) {
                low = mid + 1;
            } else {
                high = mid;
           }
        }
        pw.println(low - 1);
        pw.close();
    }

    private static boolean check(int[] position, int mid, int m) {
        int cnt = 1, cur = position[0];
        for (int i = 1; i < position.length; i++) {
            if (position[i] - cur >= mid) {
                cur = position[i];
                cnt++;
                if (cnt == m) {
                    return true;
                }
            }
        }
        return false;
    }
}
