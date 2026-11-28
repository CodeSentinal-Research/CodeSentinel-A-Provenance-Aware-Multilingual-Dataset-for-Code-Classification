import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        System.out.println(minOperations(X, Y));
    }

    private static int minOperations(int X, int Y) {
        int operations = 0;
        while (Y != X) {
            if (Y < X) {
                Y = Y * 2;
            } else {
                Y = Y - 1;
            }
            operations++;
        }
        return operations;
    }
}
