import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(height(N));
    }

    private static int height(int N) {
        int height = 0;
        while (N > 0) {
            N >>= 1;
            height++;
        }
        return height;
    }
}
