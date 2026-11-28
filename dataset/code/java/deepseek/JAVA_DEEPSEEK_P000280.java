import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next();
        String s2 = scanner.next();

        if (isAnagram(s1, s2)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static boolean isAnagram(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        int[] count = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            count[s1.charAt(i) - 'a']++;
            count[s2.charAt(i) - 'a']--;
        }

        for (int i : count) {
            if (i != 0) {
                return false;
            }
        }

        for (int i = 0; i < s1.length() - 1; i++) {
            if (isValid(s1, i)) {
                return true;
            }
        }

        for (int i = 0; i < s1.length() - 1; i++) {
            if (isValid(s2, i)) {
                return true;
            }
        }

        return false;
    }

    private static boolean isValid(String s, int index) {
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            if (i != index) {
                count[s.charAt(i) - 'a']++;
            }
        }

        for (int i = 0; i < count.length; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
}
