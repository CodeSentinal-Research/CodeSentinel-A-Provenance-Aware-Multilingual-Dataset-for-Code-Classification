import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        String longest = "";
        for (int i = 0; i < s.length(); i++) {
            // Odd length
            String odd = expandAroundCenter(s, i, i);
            if (odd.length() > longest.length()) {
                longest = odd;
            }
            // Even length
            String even = expandAroundCenter(s, i, i + 1);
            if (even.length() > longest.length()) {
                longest = even;
            }
        }
        
        System.out.println(longest);
    }
    
    private static String expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return s.substring(left + 1, right);
    }
}
