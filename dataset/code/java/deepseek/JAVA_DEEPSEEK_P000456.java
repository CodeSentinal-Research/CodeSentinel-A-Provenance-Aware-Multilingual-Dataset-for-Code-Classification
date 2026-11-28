import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int H = scanner.nextInt();
        int[] piles = new int[N];
        for (int i = 0; i < N; i++) {
            piles[i] = scanner.nextInt();
        }
        System.out.println(minEatingSpeed(piles, H));
    }

    public static int minEatingSpeed(int[] piles, int H) {
        int left = 1, right = 1_000_000_000;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (canEatAll(piles, mid, H)) {
                right = mid;
            } else {
                left = mid + 1;
           }
        }
        return left;
    }

    public static boolean canEatAll(int[] piles, int K, int H) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + K - 1) / K;
        }
        return hours <= H;
    }
}
