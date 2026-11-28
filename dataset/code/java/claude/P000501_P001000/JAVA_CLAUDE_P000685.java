import java.util.Scanner;
public class Solution {
    public boolean isPalindrome(String s) {
        return s.equals(new StringBuilder(s).reverse().toString());
    }
    public static void main(String[] args) {
        String s = new Scanner(System.in).next();
        System.out.println(new Solution().isPalindrome(s) ? "Yes" : "No");
    }
}
