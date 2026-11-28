import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static int[] stalls;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] st = br.readLine().split(" ");
        n = Integer.parseInt(st[0]);
        k = Integer.parseInt(st[1]);
        stalls = new int[n];
        for (int i = 0; i < n; i++) {
            stalls[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(stalls);
        System.out.println(binarySearch());
    }

    static int binarySearch() {
        int low = 0, high = stalls[n - 1] - stalls[0];
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (canPlaceCows(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    static boolean canPlaceCows(int minDist) {
        int count = 1;
        int lastCow = stalls[0];
        for (int i = 1; i < n; i++) {
            if (stalls[i] - lastCow >= minDist) {
                lastCow = stalls[i];
                count++;
                if (count == k) {
                    return true;
                }
            }
        }
        return false;
    }
}
