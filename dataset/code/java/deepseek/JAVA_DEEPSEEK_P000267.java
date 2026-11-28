import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the string:");
        String S = scanner.nextLine();
        System.out.println("Enter the character to be replaced:");
        char oldChar = scanner.next().charAt(0);
        System.out.println("Enter the character to replace with:");
        char newChar = scanner.next().charAt(0);
        String result = S.replace(oldChar, newChar);
        System.out.println("The modified string is: " + result);
    }
}