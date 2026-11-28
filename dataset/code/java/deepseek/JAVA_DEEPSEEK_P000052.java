import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char uppercase = scanner.next().charAt(0);
        char lowercase = Character.toLowerCase(uppercase);
        System.out.println(lowercase);
    }
}
