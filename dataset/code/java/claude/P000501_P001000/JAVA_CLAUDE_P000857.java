import java.util.Scanner;
public class Solution {
    public long power(long base, long exp, long mod) {
        long result = 1; base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) result = result * base % mod;
            base = base * base % mod; exp >>= 1;
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(new Solution().power(sc.nextLong(), sc.nextLong(), sc.nextLong()));
    }
}
