import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        double probability = binomialCoefficient(N, K) * Math.pow(0.5, N);
        System.out.println(probability);
    }

    private static double binomialCoefficient(int n, int k) {
        double res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (n - k + i) / i;
        }
        return res;
    }
}
