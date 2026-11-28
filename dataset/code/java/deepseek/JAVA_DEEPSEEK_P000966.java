import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int n = scanner.nextInt();
        boolean[] congruences = new boolean[n];
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            congruences[i] = (x % a == b);
        }
        for (boolean congruence : congruences) {
            if (!congruence) {
                System.out.println("false");
                return;
           }
        }
        System.out.println("true");
    }
}
