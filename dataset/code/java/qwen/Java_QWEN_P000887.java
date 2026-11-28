import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long sq = n * n;
        long sum = 0;
        while(sq > 0) {
            sum += sq % 10;
            sq /= 10;
        }
        System.out.println(sum == n ? "true" : "false");
    }
}
