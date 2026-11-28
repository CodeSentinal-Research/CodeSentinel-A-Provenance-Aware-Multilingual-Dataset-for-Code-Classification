import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long low = 0, high = n, res = 0;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if (mid * mid <= n) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        System.out.println(res);
    }
}
