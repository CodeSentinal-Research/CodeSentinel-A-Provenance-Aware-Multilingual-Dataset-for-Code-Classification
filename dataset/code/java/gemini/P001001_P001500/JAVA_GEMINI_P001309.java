import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int s = sc.nextInt(), n = sc.nextInt(), m = sc.nextInt();
            int totalFood = s * m;
            if ((n - m) * 6 < m && s > 6) {
                System.out.println(-1);
            } else if (m > n) {
                System.out.println(-1);
            } else {
                System.out.println((totalFood + n - 1) / n);
            }
        }
        sc.close();
    }
}