import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long m = sc.nextLong();
        // Use BigInteger for safety or manual multiplication if within range
        // Since constraints are 10^18, a*b can overflow long.
        // Using BigInteger for correctness
        BigInteger ba = BigInteger.valueOf(a);
        BigInteger bb = BigInteger.valueOf(b);
        BigInteger bm = BigInteger.valueOf(m);
        System.out.println(ba.multiply(bb).mod(bm));
    }
}
