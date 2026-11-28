import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String A = scanner.next();
        String B = scanner.next();
        System.out.println(longestUncommonSubsequence(A, B));
    }

    private static int longestUncommonSubsequence(String A, String B) {
        if (A.length() != B.length()) {
            return Math.max(A.length(), B.length());
        }
        if (!A.equals(B)) {
            return A.length();
        }
        return -1;
    }
}
