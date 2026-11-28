import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        // Stars and Bars: C(n+k-1, k-1)
        // Using BigInteger for large results
        BigInteger res = comb(n + k - 1, k - 1);
        System.out.println(res);
    }
    static BigInteger comb(int n, int r) {
        if(r > n) return BigInteger.ZERO;
        if(r == 0) return BigInteger.ONE;
        BigInteger res = BigInteger.ONE;
        for(int i=0; i<r; i++) {
            res = res.multiply(BigInteger.valueOf(n - i));
            res = res.divide(BigInteger.valueOf(i + 1));
        }
        return res;
    }
}
