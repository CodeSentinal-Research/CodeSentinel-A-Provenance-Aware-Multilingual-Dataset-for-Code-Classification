import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int square = n * n;
        int sum = 0;
        while (square != 0) {
            sum += square % 10;
            square = square / 10;
        }
        if (sum == n) {
            System.out.println("Neon");
       } else {
            System.out.println("Not Neon");
        }
    }
}
