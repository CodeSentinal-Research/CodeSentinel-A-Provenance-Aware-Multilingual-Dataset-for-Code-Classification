import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int P = scanner.nextInt();
        int R = scanner.nextInt();
        int T = scanner.nextInt();
        System.out.println((P * R * T) / 100);
    }
}
