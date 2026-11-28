import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] candies = new int[n];
        for (int i = 0; i < n; i++) {
            candies[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();
        System.out.println(maxCandies(candies, k));
    }

    private static int maxCandies(int[] candies, int k) {
        int left = 1;
        int right = 1000000000;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canAllocate(candies, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private static boolean canAllocate(int[] candies, int k, int target) {
        int count = 0;
        for (int candy : candies) {
            count += candy / target;
        }
        return count >= k;
    }
}
