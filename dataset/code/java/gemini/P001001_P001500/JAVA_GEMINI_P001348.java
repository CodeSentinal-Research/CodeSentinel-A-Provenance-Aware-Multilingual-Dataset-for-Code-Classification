import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt(), r = sc.nextInt(), c = sc.nextInt();
            int ans = Math.max(r - 1, n - r) + Math.max(c - 1, m - c);
            System.out.println(ans);
        }
        sc.close();
    }
}