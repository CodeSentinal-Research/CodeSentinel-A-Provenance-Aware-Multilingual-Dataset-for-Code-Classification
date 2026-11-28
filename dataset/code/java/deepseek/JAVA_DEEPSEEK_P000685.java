import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(isPalindrome(s, 0));
    }

    public static boolean isPalindrome(String s, int index) {
        int len = s.length();
        if (index >= len / 2) {
            return true;
        }
        if (s.charAt(index) != s.charAt(len - index - 1)) {
            return false;
       }
        return isPalindrome(s, index + 1);
    }
}
