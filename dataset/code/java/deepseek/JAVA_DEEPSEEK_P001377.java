import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        System.out.println(isIsomorphic(s, t) ? "YES" : "NO");
    }

    public static boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Character> s2t = new HashMap<>();
        Map<Character, Character> t2s = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char sChar = s.charAt(i);
            char tChar = t.charAt(i);

            if (s2t.containsKey(sChar)) {
                if (s2t.get(sChar) != tChar) {
                    return false;
                }
            } else {
                s2t.put(sChar, tChar);
            }

            if (t2s.containsKey(tChar)) {
                if (t2s.get(tChar) != sChar) {
                    return false;
                }
            } else {
                t2s.put(tChar, sChar);
            }
        }

        return true;
    }
}
