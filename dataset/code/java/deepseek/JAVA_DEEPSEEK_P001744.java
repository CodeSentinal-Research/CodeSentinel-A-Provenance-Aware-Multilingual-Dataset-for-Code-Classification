import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        boolean hasTwoChildren = false;
        for (int i = 0; i < N; i++) {
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            if (left != 0 && right != 0) {
                hasTwoChildren = true;
            }
        }
        System.out.println(hasTwoChildren ? "NO" : "YES");
    }
}
