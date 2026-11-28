import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long low = 0, high = n;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            if(mid * mid == n) { System.out.println(mid); return; }
            else if(mid * mid < n) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println(high);
    }
}
