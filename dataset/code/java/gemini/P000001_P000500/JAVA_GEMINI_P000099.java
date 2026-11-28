import java.util.Scanner;

public class Solution {
    public static void printFloydTriangle(int rows) {
        int num = 1;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(num + (j == i ? "" : " "));
                num++;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int rows = sc.nextInt();
            printFloydTriangle(rows);
        }
        sc.close();
    }
}