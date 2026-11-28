import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        int n = a.length();
        for (int i = 1; i < n; i++) {
            String prefixA = a.substring(0, i);
            String suffixB = b.substring(i);
            String combined = prefixA + suffixB;
            if (isPalindrome(combined)) {
                System.out.println("Yes"); return;
            }
            String prefixB = b.substring(0, i);
            String suffixA = a.substring(i);
            combined = prefixB + suffixA;
            if (isPalindrome(combined)) {
                System.out.println("Yes"); return;
            }
        }
        System.out.println("No");
    }
    static boolean isPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }
}
