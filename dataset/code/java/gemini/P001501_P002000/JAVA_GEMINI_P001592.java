import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), x = sc.nextInt();
            long curSum = 0;
            int ans = -1;

            for (int i = 0; i < n; i++) {
                curSum += sc.nextInt();
                if (curSum >= x && ans == -1) {
                    ans = i + 1;
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}