import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int k = scanner.nextInt();
        System.out.println(maxVowels(s, k));
    }

    public static int maxVowels(String s, int k) {
        int max = 0;
        int count = 0;
        int vowels = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i >= k) {
                if (s.charAt(i - k) == 'a' || s.charAt(i - k) == 'e' || s.charAt(i - k) == 'i' || s.charAt(i - k) == 'o' || s.charAt(i - k) == 'u') {
                    count--;
                }
            }
            if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u') {
                count++;
                vowels = Math.max(vowels, count);
            }
        }
        return vowels;
    }
}
