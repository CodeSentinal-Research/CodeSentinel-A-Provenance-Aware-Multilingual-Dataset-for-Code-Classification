import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long cur = 0;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                cur += sc.nextInt();
                if (cur > 0) ans++;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}