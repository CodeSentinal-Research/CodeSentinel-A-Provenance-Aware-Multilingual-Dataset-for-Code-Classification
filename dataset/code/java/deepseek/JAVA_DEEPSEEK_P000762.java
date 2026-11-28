import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        String p = scanner.next();
        System.out.println(isMatch(s, p));
    }

    public static boolean isMatch(String s, String p) {
        if (p.isEmpty())   
            return s.isEmpty();
        
        boolean firstMatch = (!s.isEmpty() &&
                            (p.charAt(0) == s.charAt(0) || p.charAt(0) == '?'));

        if (p.charAt(0) == '*') {
            for (int i = 0; i <= s.length(); i++) {
                if (isMatch(s.substring(i), p.substring(1))) {
                    return true;
                }
            }
            return false;
        }
        return firstMatch && isMatch(s.substring(1), p.substring(1));
    }
}
