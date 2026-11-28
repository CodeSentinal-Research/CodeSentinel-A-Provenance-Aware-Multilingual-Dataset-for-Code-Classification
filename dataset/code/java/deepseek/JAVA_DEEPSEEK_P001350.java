import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String result = kthLexicographicallySmallestHappyString(N, K);
        System.out.println(result.isEmpty() ? "Empty" : result);
    }

    private static String kthLexicographicallySmallestHappyString(int N, int K) {
        if (N == 1) {
            return "a";
        }
        if (K == 1) {
            return "b";
        }
        if (K == 2) {
            return "c";
        }
        return "";
    }
}
