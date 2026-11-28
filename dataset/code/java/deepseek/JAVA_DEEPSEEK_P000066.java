import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int base = scanner.nextInt();
        int height = scanner.nextInt();
        System.out.println((base * height) / 2.0);
    }
}
