import java.util.*;

public class Solution {
    private static long wordToVal(String w) {
        long val = 0;
        for (char c : w.toCharArray()) {
            val = val * 10 + (c - 'a');
        }
        return val;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String w1 = scanner.next();
            String w2 = scanner.next();
            String w3 = scanner.next();
            System.out.println(wordToVal(w1) + wordToVal(w2) == wordToVal(w3) ? "Yes" : "No");
        }
    }
}