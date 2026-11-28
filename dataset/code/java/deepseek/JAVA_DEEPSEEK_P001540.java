import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        long result = countVowelSubstrings(s);
        System.out.println(result);
    }

    public static long countVowelSubstrings(String s) {
        long count = 0;
        int vowelCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                vowelCount++;
            } else {
                if (vowelCount == 5) {
                    count++;
                }
                vowelCount = 0;
            }
        }
        if (vowelCount == 5) {
            count++;
        }
        return count;
    }

    public static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
