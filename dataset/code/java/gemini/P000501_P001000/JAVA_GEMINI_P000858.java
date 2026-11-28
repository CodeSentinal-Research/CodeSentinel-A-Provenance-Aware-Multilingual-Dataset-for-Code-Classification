import java.util.Scanner;

public class Solution {
    public static int findPosition(int n) {
        if (n <= 0 || (n & (n - 1)) != 0) return -1;
        return Integer.numberOfTrailingZeros(n) + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(findPosition(n));
        }
        sc.close();
    }
}