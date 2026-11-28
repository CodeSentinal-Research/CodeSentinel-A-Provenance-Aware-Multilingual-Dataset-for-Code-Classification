import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        findPaths(n, m, "");
    }

    private static void findPaths(int n, int m, String path) {
        if (n == 1 && m == 1) {
            System.out.println(path);
            return;
        }

        if (n > 1) {
            findPaths(n - 1, m, path + "V");
        }

        if (m > 1) {
            findPaths(n, m - 1, path + "H");
        }

        if (n > 1 && m > 1) {
            findPaths(n - 1, m - 1, path + "D");
        }
    }
}
