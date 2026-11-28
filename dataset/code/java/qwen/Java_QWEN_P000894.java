import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        while(b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        System.out.println(a);
    }
}
