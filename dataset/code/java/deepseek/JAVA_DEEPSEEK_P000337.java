import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int maxScore = 0;
        int[] count = new int[2];

        for (char c : S.toCharArray()) {
            count[c - '0']++;
        }

        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            count[c - '0']--;
            if (c == '0') {
                maxScore = Math.max(maxScore, count[1]);
            } else {
                maxScore = Math.max(maxScore, count[0] + count[1]);
            }
        }

        System.out.println(maxScore);
    }
}
