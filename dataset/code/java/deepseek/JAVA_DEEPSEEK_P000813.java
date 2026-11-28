import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        System.out.println(mySqrt(x));
    }

    public static int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int start = 0;
        int end = x;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid <= x / mid && (mid + 1) > x / (mid + 1)) {
                return mid;
           }
            if (mid > x / mid) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
}
