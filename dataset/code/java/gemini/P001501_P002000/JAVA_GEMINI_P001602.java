import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long cur = 0, maxAbs = 0;
            for (int i = 0; i < n; i++) {
                cur += sc.nextInt();
                maxAbs = Math.max(maxAbs, Math.abs(cur));
            }
            System.out.println(maxAbs);
        }
        sc.close();
    }
}