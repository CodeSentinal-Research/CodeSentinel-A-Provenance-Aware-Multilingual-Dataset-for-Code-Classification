import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.close();

        System.out.println(beautifulArrangement(N));
    }

    private static int beautifulArrangement(int N) {
        if (N == 1) {
            return 1;
        }

        int result = 0;
        for (int i = 2; i <= N; i++) {
            if (isBeautiful(i, N)) {
                result += countArrangement(N - 1, i);
            }
        }

        return result;
    }

    private static boolean isBeautiful(int num, int divisor) {
        return num % divisor == 0 || divisor % num == 0;
    }

    private static int countArrangement(int N, int divisor) {
        if (N == 1) {
            return 1;
        }

        int result = 0;
        for (int i = 2; i <= N; i++) {
            if (isBeautiful(i, divisor)) {
                result += countArrangement(N - 1, i);
            }
        }

        return result;
    }
}
