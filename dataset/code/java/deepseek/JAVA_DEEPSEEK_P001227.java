import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();

        long[] derangements = new long[n + 1];
        derangements[0] = 1;
        derangements[1] = 0;

        for(int i = 2; i <= n; i++) {
            derangements[i] = (i - 1) * (derangements[i - 1] + derangements[i - 2]);
        }

        System.out.println(derangements[n]);
    }
}
