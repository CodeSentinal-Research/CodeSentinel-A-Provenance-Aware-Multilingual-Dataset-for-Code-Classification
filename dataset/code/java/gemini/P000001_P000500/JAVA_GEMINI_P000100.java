import java.util.Scanner;

public class Solution {
    public static void printPascalTriangle(int n) {
        for (int i = 0; i < n; i++) {
            long val = 1;
            for (int j = 0; j <= i; j++) {
                System.out.print(val + (j == i ? "" : " "));
                val = val * (i - j) / (j + 1);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            printPascalTriangle(n);
        }
        sc.close();
    }
}