import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(isPalindrome(n) ? "Palindrome" : "Not Palindrome");
    }

    private static boolean isPalindrome(int n) {
        if (n < 0) {
            return false;
        }
        int reverse = 0;
        int original = n;
        while (n != 0) {
            reverse = reverse * 10 + n % 10;
            n = n / 10;
        }
        return original == reverse;
    }
}
