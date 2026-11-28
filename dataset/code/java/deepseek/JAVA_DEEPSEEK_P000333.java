import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = scanner.nextLine();
        }
        System.out.println(numMatchingSubseq(S, words));
    }

    public static int numMatchingSubseq(String S, String[] words) {
        int count = 0;
        int sIndex = 0;
        for (String word : words) {
            if (isSubseq(S, word, sIndex)) {
                count++;
            }
        }
        return count;
    }

    public static boolean isSubseq(String S, String word, int sIndex) {
        int wIndex = 0;
        for (int s = sIndex; s < S.length() && wIndex < word.length(); s++) {
            if (S.charAt(s) == word.charAt(wIndex)) {
                wIndex++;
            }
        }
        return wIndex == word.length();
    }
}
