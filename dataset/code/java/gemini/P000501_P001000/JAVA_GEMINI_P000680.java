import java.util.*;
public class Solution {
    static void printNTo1(int n) {
        if (n <= 0) return;
        System.out.print(n + " ");
        printNTo1(n - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            printNTo1(n);
            System.out.println();
        }
    }
}