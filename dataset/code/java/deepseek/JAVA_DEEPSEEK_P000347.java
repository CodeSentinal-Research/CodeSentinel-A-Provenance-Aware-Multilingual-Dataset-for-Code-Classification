import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int K = scanner.nextInt();
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < S.length(); i += 2*K) {
            int end = Math.min(i + K, S.length());
            String substring = S.substring(i, end);
            result.append(new StringBuilder(substring).reverse());

            if (end < S.length()) {
                result.append(S, end, Math.min(end + K, S.length()));
           }
        }

        System.out.println(result.toString());
    }
}
