import java.util.Scanner;

public class Solution {
    public static boolean isHarshad(int n) {
        if (n <= 0) return false;
        int sum = 0, temp = n;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return n % sum == 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(isHarshad(n) ? "YES" : "NO");
        }
        sc.close();
    }
}