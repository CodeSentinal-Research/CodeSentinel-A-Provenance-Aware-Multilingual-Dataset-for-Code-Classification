import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            if (scanner.hasNextLong()) {
                long a = scanner.nextLong();
                if (scanner.hasNextLong()) {
                    long b = scanner.nextLong();
                    System.out.println(a + b);
                }
            }
        }
    }
}