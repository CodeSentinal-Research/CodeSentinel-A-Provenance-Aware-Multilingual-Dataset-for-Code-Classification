import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char c = sc.next().charAt(0);
        boolean isSpecial = !Character.isLetterOrDigit(c) && !Character.isWhitespace(c);
        System.out.println(isSpecial ? "Special Symbol" : "Not Special Symbol");
    }
}
