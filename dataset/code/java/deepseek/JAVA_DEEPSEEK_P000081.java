import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char c = scanner.next().charAt(0);
        if (Character.isDigit(c)) {
            System.out.println("Digit");
        } else {
            System.out.println("Not Digit");
        }
    }
}
