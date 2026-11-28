import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    private static boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public static long countEqualVowelsConsonants(String s) {
        int prefix = 0;
        long count = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        freq.put(0, 1);
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isLetter(c)) {
                prefix += isVowel(c) ? 1 : -1;
                count += freq.getOrDefault(prefix, 0);
                freq.put(prefix, freq.getOrDefault(prefix, 0) + 1);
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            System.out.println(countEqualVowelsConsonants(s));
        }
        sc.close();
    }
}