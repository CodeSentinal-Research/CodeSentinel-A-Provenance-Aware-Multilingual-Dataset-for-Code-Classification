import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            for (int i = 0; i < m; i++) {
                sc.nextInt();
                sc.nextInt();
            }
            System.out.println(m);
        }
        sc.close();
    }
}