import java.util.*;
public class Solution {
    static boolean isPalRec(String s, int l, int r) {
        if (l >= r) return true;
        if (s.charAt(l) != s.charAt(r)) return false;
        return isPalRec(s, l + 1, r - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            System.out.println(isPalRec(s, 0, s.length() - 1) ? "true" : "false");
        }
    }
}