import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        System.out.println(minCut(str));
    }

    public static int minCut(String s) {
        if (s == null || s.length() == 0) {
            return 0;
       }
        int n = s.length();
        boolean[][] palindrome = new boolean[n][n];
        int[] cut = new int[n+1];
        for (int i = 0; i <= n; i++) {
            cut[i] = i - 1;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (s.charAt(i) == s.charAt(j) && (j - i < 2 || palindrome[i+1][j-1])) {
                    palindrome[i][j] = true;
                    cut[j] = Math.min(cut[j], cut[i] + 1);
                }
            }
        }
        return cut[n];
    }
}
