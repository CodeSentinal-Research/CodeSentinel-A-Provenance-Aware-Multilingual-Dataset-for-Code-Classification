import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] bloomDay = new int[n];
        for (int i = 0; i < n; i++) {
            bloomDay[i] = scanner.nextInt();
        }
        int m = scanner.nextInt();
        int k = scanner.nextInt();
        System.out.println(minDays(bloomDay, m, k));
    }

    public static int minDays(int[] bloomDay, int m, int k) {
        if (m * k > bloomDay.length) {
            return -1;
        }
        int low = 1, high = (int)1e9;
        while (low < high) {
            int mid = (low + high) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
           }
        }
        return low;
    }

    public static boolean canMake(int[] bloomDay, int m, int k, int day) {
        int flowers = 0;
        for (int d : bloomDay) {
            if (d <= day) {
                flowers++;
                if (flowers == k) {
                    m--;
                    if (m == 0) {
                        return true;
                    }
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return false;
    }
}
