import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            if (scanner.hasNextLong()) {
                long first = scanner.nextLong();
                if (scanner.hasNextLong()) {
                    long second = scanner.nextLong();
                    System.out.println(first + second);
                }
            }
        }
    }
}