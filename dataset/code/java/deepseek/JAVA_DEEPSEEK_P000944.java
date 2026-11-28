import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(divisorGame(N));
    }

    public static boolean divisorGame(int N) {
        return N % 2 == 0;
    }
}
