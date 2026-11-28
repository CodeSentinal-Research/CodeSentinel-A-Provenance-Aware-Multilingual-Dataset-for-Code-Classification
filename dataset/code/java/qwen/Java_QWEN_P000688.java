import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println(n == 0 ? 1 : countDigits(n));
    }
    static int countDigits(long n) {
        if(n < 10) return 1;
        return 1 + countDigits(n / 10);
    }
}
