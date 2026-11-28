import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int[] stalls = new int[n];
        for (int i = 0; i < n; i++) {
            stalls[i] = sc.nextInt();
        }
        Arrays.sort(stalls);
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(stalls, n, c, mid)) {
                res = mid;
                low = mid + 1;
           } else {
                high = mid - 1;
            }
        }
        System.out.println(res);
    }

    public static boolean isPossible(int[] stalls, int n, int c, int minDist) {
        int count = 1;
        int lastStall = stalls[0];
        for (int i = 1; i < n; i++) {
            if (stalls[i] - lastStall >= minDist) {
                lastStall = stalls[i];
                count++;
                if (count == c) {
                    return true;
                }
            }
        }
        return false;
    }
}
