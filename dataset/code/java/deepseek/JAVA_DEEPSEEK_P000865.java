import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int xor = 0;
        for (int i = 0; i < n; i++) {
            xor ^= scanner.nextInt();
        }
        System.out.println(xor);
    }
}
