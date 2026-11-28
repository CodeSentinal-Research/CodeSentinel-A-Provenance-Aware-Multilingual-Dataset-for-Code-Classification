import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(reverseString(s));
    }

    public static String reverseString(String s) {
        if (s.isEmpty()) {
            return s;
        } else {
            return reverseString(s.substring(1)) + s.charAt(0);
       }
    }
}
