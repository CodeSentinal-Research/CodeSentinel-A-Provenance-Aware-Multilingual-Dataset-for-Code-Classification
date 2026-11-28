import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int S = scanner.nextInt();
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.close();

        if (S <= M) {
            System.out.println(1);
        } else {
            int days = (S - M) / (N - M) + 1;
            if (days <= S) {
                System.out.println(days);
            } else {
                System.out.println(-1);
            }
        }
    }
}
