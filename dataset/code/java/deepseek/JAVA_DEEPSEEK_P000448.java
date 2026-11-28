import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(binarySearch(n));
    }

    private static int binarySearch(int n) {
        int start = 0;
        int end = n;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long square = (long)mid * mid;
            if (square == n) {
                return mid;
            } else if (square < n) {
                start = mid + 1;
           } else {
                end = mid - 1;
            }
        }
        return start - 1;
    }
}
