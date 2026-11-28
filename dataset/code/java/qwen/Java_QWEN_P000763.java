import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String p = sc.next();
        System.out.println(isRegexMatch(s, p, s.length(), p.length()) ? "true" : "false");
    }
    static boolean isRegexMatch(String s, String p, int i, int j) {
        if(j == 0) return i == 0;
        if(j > 1 && p.charAt(j-1) == '*') {
            return isRegexMatch(s, p, i, j-2) || 
                   (i > 0 && (p.charAt(j-2) == '.' || p.charAt(j-2) == s.charAt(i-1)) && isRegexMatch(s, p, i-1, j));
        }
        if(i > 0 && (p.charAt(j-1) == '.' || p.charAt(j-1) == s.charAt(i-1)))
            return isRegexMatch(s, p, i-1, j-1);
        return false;
    }
}
