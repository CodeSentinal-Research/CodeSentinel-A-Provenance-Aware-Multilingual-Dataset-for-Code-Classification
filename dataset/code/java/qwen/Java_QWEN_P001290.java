import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        
        long minTwo = Math.min(a, Math.min(b, c));
        long sum = a + b + c;
        
        System.out.println(Math.min(sum / 2, sum - minTwo));
    }
}
