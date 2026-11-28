import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char c = scanner.next().charAt(0);
        if (Character.isUpperCase(c)) {
            System.out.println("Uppercase");
        } else {
            System.out.println("Lowercase");
        }
    }
}
