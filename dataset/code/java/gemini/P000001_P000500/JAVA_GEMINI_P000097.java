import java.util.Scanner;

public class Solution {
    public static boolean isDuckNumber(String s) {
        s = s.trim();
        if (s.isEmpty() || s.charAt(0) == '0') return false;
        return s.contains("0");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            System.out.println(isDuckNumber(s) ? "YES" : "NO");
        }
        sc.close();
    }
}