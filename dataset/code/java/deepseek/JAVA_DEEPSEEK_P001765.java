import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        boolean[] lengths = new boolean[N];
        for (int i = 0; i < N; i++) {
            lengths[i] = scanner.nextInt() == 1;
        }
        boolean result = checkPathLengths(lengths);
        System.out.println(result ? "YES" : "NO");
    }

    private static boolean checkPathLengths(boolean[] lengths) {
        boolean result = true;
        for (int i = 1; i < lengths.length; i++) {
            if (lengths[i] != lengths[0]) {
                result = false;
                break;
            }
        }
        return result;
    }
}
