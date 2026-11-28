import java.util.Scanner;

public class Solution {
    public static int toggleKthBit(int n, int k) {
        return n ^ (1 << k);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            System.out.println(toggleKthBit(n, k));
        }
        sc.close();
    }
}