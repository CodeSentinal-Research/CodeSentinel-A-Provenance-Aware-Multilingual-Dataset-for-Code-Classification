import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(countInternalNodes(N));
    }

    private static int countInternalNodes(int N) {
        int count = 0;
        for (int i = 2; i <= N; i++) {
            count += (1 << (i - 1));
        }
        return count;
    }
}
