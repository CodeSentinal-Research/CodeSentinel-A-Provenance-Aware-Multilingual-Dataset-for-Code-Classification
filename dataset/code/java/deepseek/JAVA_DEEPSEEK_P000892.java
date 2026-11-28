import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        StringBuilder sb = new StringBuilder();
        for (long i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                sb.append(i).append(" ");
                n /= i;
           }
        }
        if (n > 1) {
            sb.append(n);
        }
        System.out.println(sb.toString());
    }
}