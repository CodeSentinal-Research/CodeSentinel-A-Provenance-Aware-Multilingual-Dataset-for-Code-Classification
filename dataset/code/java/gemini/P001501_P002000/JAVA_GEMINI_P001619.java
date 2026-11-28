import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
            int ans = 0;
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (i >= l && i <= r) ans ^= x;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}