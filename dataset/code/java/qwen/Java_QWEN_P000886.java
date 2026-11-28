import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long sum = 0, t = n;
        while(t > 0) {
            sum += t % 10;
            t /= 10;
        }
        System.out.println(n % sum == 0 ? "true" : "false");
    }
}
