import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                System.out.print(sc.nextInt() + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}