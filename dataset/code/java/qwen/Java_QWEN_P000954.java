import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        
        long[] res = extendedGcd(a, b);
        System.out.println(res[0] + " " + res[1] + " " + res[2]);
    }
    static long[] extendedGcd(long a, long b) {
        if(b == 0) return new long[]{1, 0, a};
        long[] res = extendedGcd(b, a % b);
        long x1 = res[0], y1 = res[1], g = res[2];
        return new long[]{y1, x1 - (a / b) * y1, g};
    }
}
