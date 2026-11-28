import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        printLexico(0, n, "");
    }

    private static void printLexico(int start, int end, String prefix) {
        if (start > end) {
            return;
        }
        System.out.println(prefix + start);
        for (int i = 0; i <= 9; i++) {
            if (Long.parseLong(prefix + i) <= end) {
                printLexico(start + 1, end, prefix + i);
            }
       }
    }
}
