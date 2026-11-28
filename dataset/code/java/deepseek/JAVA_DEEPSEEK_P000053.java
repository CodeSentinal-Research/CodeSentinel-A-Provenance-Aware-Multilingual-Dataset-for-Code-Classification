import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char lowercase = scanner.next().charAt(0);
        char uppercase = Character.toUpperCase(lowercase);
        System.out.println(uppercase);
    }
}
