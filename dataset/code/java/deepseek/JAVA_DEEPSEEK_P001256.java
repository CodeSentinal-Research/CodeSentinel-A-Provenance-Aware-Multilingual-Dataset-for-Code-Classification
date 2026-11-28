import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(minDeletions(s));
    }

    public static int minDeletions(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int deletions = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (freq[i] > 2) {
                    deletions += freq[i] - 2;
                    freq[i] = 2;
                }
                else {
                    freq[i] = 0;
                }
            }
        }

        int totalDeletions = 0;
        for (int i = 0; i < 26; i++) {
            totalDeletions += freq[i];
        }

        return totalDeletions;
    }
}
