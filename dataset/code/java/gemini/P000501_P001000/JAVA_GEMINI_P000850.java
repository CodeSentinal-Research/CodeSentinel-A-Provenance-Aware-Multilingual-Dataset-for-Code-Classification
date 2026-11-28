import java.util.Scanner;

public class Solution {
    public static boolean isKthBitSet(int n, int k) {
        return (n & (1 << k)) != 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            System.out.println(isKthBitSet(n, k) ? "YES" : "NO");
        }
        sc.close();
    }
}