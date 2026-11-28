import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int[] weights = new int[n];
        int max = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            weights[i] = sc.nextInt();
            max = Math.max(max, weights[i]);
            sum += weights[i];
        }
        int l = max, r = sum;
        while (l < r) {
            int mid = (l + r) / 2;
            if (canShip(weights, mid, d)) {
                r = mid;
            } else {
                l = mid + 1;
           }
        }
        System.out.println(l);
    }

    private static boolean canShip(int[] weights, int capacity, int d) {
        int days = 1;
        int cur = 0;
        for (int weight : weights) {
            if (cur + weight > capacity) {
                days++;
                cur = 0;
            }
            cur += weight;
        }
        return days <= d;
    }
}
