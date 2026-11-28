import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(nextPrime(n));
    }

    private static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static int nextPrime(int n) {
        if (n <= 1) {
            return 2;
        }
        int prime = n;
        boolean found = false;
        while (!found) {
            prime++;
            if (isPrime(prime)) {
                found = true;
            }
        }
        return prime;
    }
}
