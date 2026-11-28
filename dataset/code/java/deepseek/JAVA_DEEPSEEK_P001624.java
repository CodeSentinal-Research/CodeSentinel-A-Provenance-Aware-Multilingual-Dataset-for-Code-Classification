import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] diffArray = new long[n];
        long[] originalArray = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            diffArray[i] = scanner.nextLong();
            sum += diffArray[i];
        }
        if (sum % 2 != 0) {
            System.out.println("-1");
            return;
        }
        sum /= 2;
        long left = 0, right = Long.MAX_VALUE;
        while (left < right) {
            long mid = (left + right + 1) >> 1;
            if (check(diffArray, mid)) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        System.out.println(left + " " + (left * 2));
    }

    private static boolean check(long[] diffArray, long limit) {
        long sum = 0;
        for (long diff : diffArray) {
            sum += diff;
            if (sum > limit) {
                return false;
            }
        }
        return true;
    }
}
