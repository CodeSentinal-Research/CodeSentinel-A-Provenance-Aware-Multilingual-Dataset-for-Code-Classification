import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] phi = new int[n+1];

        for (int i = 1; i <= n; i++) {
            phi[i] = i;
        }

        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) {
                for (int j = i; j <= n; j += i) {
                    phi[j] = (phi[j] / i) * (i - 1);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            System.out.print(phi[i] + " ");
        }
    }
}
