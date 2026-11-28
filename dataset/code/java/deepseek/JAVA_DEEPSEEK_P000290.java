import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.next();
        String pattern = scanner.next();
        List<Integer> result = findAnagrams(text, pattern);
        for (int index : result) {
            System.out.print(index + " ");
        }
    }

    public static List<Integer> findAnagrams(String text, String pattern) {
        List<Integer> result = new ArrayList<>();
        if (text == null || pattern == null || text.length() < pattern.length()) {
            return result;
        }
        int[] map = new int[256];
        for (char c : pattern.toCharArray()) {
            map[c]++;
        }
        int left = 0, right = 0;
        int count = pattern.length();
        while (right < text.length()) {
            if (map[text.charAt(right)] > 0) {
                count--;
            }
            map[text.charAt(right)]--;
            right++;
            if (count == 0) {
                result.add(left);
            }
            if (right - left == pattern.length()) {
                map[text.charAt(left)]++;
                left++;
                if (map[text.charAt(left - 1)] > 0) {
                    count++;
                }
            }
        }
        return result;
    }
}
