import java.util.*;

public class Solution {
    public static boolean repeatedSubstringPattern(String s) {
        String ss = s + s;
        return ss.substring(1, ss.length() - 1).contains(s);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            System.out.println(repeatedSubstringPattern(scanner.next()) ? "Yes" : "No");
        }
    }
}