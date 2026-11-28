import java.util.Scanner;

public class Solution {
    public static long circularArrangements(int n) {
        if (n <= 1) return 1;
        long ans = 1;
        for (int i = 1; i < n; i++) {
            ans *= i;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(circularArrangements(n));
        }
        sc.close();
    }
}