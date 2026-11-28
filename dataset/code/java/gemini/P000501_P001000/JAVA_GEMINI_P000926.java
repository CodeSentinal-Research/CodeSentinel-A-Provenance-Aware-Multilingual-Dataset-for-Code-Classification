import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long n = sc.nextLong();
            System.out.println(Long.toOctalString(n) + " " + Long.toHexString(n).toUpperCase());
        }
        sc.close();
    }
}