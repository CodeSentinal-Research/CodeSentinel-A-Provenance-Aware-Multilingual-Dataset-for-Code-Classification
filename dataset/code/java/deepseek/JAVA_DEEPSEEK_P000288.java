import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(isValidPalindrome(s) ? "Yes" : "No");
    }

    private static boolean isValidPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                return isSubstringPalindrome(s, l + 1, r) || isSubstringPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }

    private static boolean isSubstringPalindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}