import java.util.Scanner;
public class Solution {
    public boolean isPalindrome(long n) {
        if (n < 0) return false;
        long original = n, rev = 0;
        while (n > 0) { rev = rev * 10 + n % 10; n /= 10; }
        return original == rev;
    }
    public static void main(String[] args) {
        long n = new Scanner(System.in).nextLong();
        System.out.println(new Solution().isPalindrome(n) ? "Yes" : "No");
    }
}
