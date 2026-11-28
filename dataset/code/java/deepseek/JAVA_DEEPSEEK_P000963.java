import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long N = scanner.nextLong();

        boolean possible = false;

        for (long i = 0; i <= N / A; i++) {
            for (long j = 0; j <= (N - i * A) / B; j++) {
                if (i * A + j * B == N) {
                    possible = true;
                    break;
                }
           
              }
        }

        System.out.println(possible ? "true" : "false");
    }
}
