import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        printNumbers(n);
    }

    public static void printNumbers(int n) {
        if (n > 0) {
            System.out.print(n + " ");
            printNumbers(n - 1);
        }
    }
}
