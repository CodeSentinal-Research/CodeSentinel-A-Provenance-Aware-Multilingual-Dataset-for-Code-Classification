import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        char C = scanner.next().charAt(0);

        int[] result = shortestToChar(S, C);
        for (int i : result) {
            System.out.print(i + " ");
        }
    }

    public static int[] shortestToChar(String S, char C) {
        int n = S.length();
        int[] result = new int[n];
        int prev = Integer.MIN_VALUE / 2;

        for (int i = 0; i < n; i++) {
            if (S.charAt(i) == C) prev = i;
            result[i] = i - prev;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (S.charAt(i) == C) prev = i;
            result[i] = Math.min(result[i], Math.abs(i - prev));
        }

        return result;
    }
}
