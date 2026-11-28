import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(arrangeCoins(n));
    }

    public static int arrangeCoins(int n) {
        long start = 0, end = n;
        while(start <= end) {
            long mid = (start + end) / 2;
            long total = mid * (mid + 1) / 2;
            if(total == n) {
                return (int)mid;
           } else if(total < n) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return (int)end;
    }
}
