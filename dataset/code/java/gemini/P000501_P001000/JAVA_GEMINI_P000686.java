import java.util.*;
public class Solution {
    static String revStr(String s) {
        if (s.length() <= 1) return s;
        return s.charAt(s.length() - 1) + revStr(s.substring(0, s.length() - 1));
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            System.out.println(revStr(scanner.next()));
        }
    }
}