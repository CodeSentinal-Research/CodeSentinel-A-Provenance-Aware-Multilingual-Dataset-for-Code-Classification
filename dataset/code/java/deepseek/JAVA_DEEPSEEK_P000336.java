import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String A = scanner.next();
        String B = scanner.next();
        scanner.close();

        if (isPalindrome(A + B) || isPalindrome(A + new StringBuilder(B).reverse().toString()) || isPalindrome(new StringBuilder(A).reverse().toString() + B) || isPalindrome(new StringBuilder(A).reverse().toString() + new StringBuilder(B).reverse().toString())) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static boolean isPalindrome(String str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}
