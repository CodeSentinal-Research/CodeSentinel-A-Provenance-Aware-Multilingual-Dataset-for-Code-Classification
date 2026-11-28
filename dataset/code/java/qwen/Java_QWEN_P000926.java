import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println(Long.toOctalString(n));
        System.out.println(Long.toHexString(n).toUpperCase());
    }
}
