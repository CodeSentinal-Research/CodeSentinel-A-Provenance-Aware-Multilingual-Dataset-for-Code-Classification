import java.util.Scanner;

public class Main {
    public static void printNumbers(int n) {
        if(n > 0) {
            printNumbers(n - 1);
            System.out.println(n);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        printNumbers(n);
    }
}
