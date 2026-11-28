import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word1 = scanner.next();
        String word2 = scanner.next();

        int[] count1 = new int[26];
        int[] count2 = new int[26];

        for (char c : word1.toCharArray()) {
            count1[c - 'a']++;
        }

        for (char c : word2.toCharArray()) {
            count2[c - 'a']++;
        }

        boolean isAlmostEquivalent = true;

        for (int i = 0; i < 26; i++) {
            if (Math.abs(count1[i] - count2[i]) > 3) {
                isAlmostEquivalent = false;
                break;
           }
        }

        System.out.println(isAlmostEquivalent ? "Yes" : "No");
    }
}
