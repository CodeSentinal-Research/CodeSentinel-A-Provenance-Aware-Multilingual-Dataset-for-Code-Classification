import java.util.*;

public class Solution {
    public static boolean detectCapitalUse(String word) {
        int caps = 0;
        for (char c : word.toCharArray()) {
            if (Character.isUpperCase(c)) caps++;
        }
        return caps == word.length() || caps == 0 || (caps == 1 && Character.isUpperCase(word.charAt(0)));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            System.out.println(detectCapitalUse(scanner.next()) ? "Yes" : "No");
        }
    }
}