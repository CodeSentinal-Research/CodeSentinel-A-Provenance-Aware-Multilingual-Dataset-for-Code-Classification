import java.util.Scanner;

public class Solution {
    public static int countTrailingZeros(int n) {
        return Integer.numberOfTrailingZeros(n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(countTrailingZeros(n));
        }
        sc.close();
    }
}