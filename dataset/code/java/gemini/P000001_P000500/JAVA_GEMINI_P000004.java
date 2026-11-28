import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long first = scanner.nextLong();
            if (scanner.hasNextLong()) {
                long second = scanner.nextLong();
                if (second == 0) {
                    System.err.println("Error: Division by zero");
                } else {
                    System.out.println(first / second);
                }
            }
        }
        scanner.close();
    }
}