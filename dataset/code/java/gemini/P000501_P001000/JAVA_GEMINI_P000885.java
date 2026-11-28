import java.util.Scanner;

public class Solution {
    public static boolean isArmstrong(int n) {
        int k = String.valueOf(n).length();
        long sum = 0, temp = n;
        while (temp > 0) {
            long d = temp % 10;
            sum += Math.pow(d, k);
            temp /= 10;
        }
        return sum == n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(isArmstrong(n) ? "YES" : "NO");
        }
        sc.close();
    }
}