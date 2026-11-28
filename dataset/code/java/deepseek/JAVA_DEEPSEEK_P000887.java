import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int square = N * N;
        int sum = 0;
        while (square != 0) {
            int digit = square % 10;
            sum += digit;
            square = square / 10;
        }
        System.out.println(sum == N);
    }
}
