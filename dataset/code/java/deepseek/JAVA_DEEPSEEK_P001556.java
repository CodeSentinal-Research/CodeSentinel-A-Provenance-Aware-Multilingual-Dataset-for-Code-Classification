import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.nextLine();
        String pattern = scanner.nextLine();
        System.out.println(countAnagramOccurrences(text, pattern));
    }

    public static int countAnagramOccurrences(String text, String pattern) {
        int count = 0;
        int patternLength = pattern.length();
        for (int i = 0; i <= text.length() - patternLength; i++) {
            String substring = text.substring(i, i + patternLength);
            if (isAnagram(substring, pattern)) {
                count++;
            }
        }
        return count;
    }

    public static boolean isAnagram(String s1, String s2) {
        int[] count = new int[256];
        for (int i = 0; i < s1.length(); i++)
            count[s1.charAt(i)]++;
        for (int i = 0; i < s2.length(); i++) {
            count[s2.charAt(i)]--;
            if (count[s2.charAt(i)] < 0)
                return false;
        }
        return true;
    }
}
