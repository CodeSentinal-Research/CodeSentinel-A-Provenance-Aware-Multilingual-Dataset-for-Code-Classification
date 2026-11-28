import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String p = sc.next();
        System.out.println(isMatch(s, p, s.length(), p.length()) ? "true" : "false");
    }
    static boolean isMatch(String s, String p, int i, int j) {
        if(j == 0) return i == 0;
        if(p.charAt(j-1) == '*') {
            return (i > 0 && isMatch(s, p, i-1, j)) || isMatch(s, p, i, j-1);
        }
        if(i > 0 && (p.charAt(j-1) == '?' || p.charAt(j-1) == s.charAt(i-1)))
            return isMatch(s, p, i-1, j-1);
        return false;
    }
}
