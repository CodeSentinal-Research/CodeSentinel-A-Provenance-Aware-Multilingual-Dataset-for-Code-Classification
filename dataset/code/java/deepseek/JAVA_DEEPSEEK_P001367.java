import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        if (N % (2 * K) == 0) {
            System.out.println("FIRST");
        } else {
            System.out.println("SECOND");
        }
    }
}
