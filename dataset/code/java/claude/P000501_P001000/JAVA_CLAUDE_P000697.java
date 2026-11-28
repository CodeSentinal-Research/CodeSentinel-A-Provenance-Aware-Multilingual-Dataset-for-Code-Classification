import java.util.Scanner;
public class Solution {
    public boolean isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        System.out.println(new Solution().isPrime(n) ? "Prime" : "Not Prime");
    }
}
