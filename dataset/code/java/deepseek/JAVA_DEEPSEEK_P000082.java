import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char c = scanner.next().charAt(0);
        if(!Character.isLetterOrDigit(c)) {
            System.out.println("Special Symbol");
        } else {
            System.out.println("Not Special Symbol");
        }
    }
}
