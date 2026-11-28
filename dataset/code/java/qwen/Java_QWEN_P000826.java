import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        
        long low = 0, high = n;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            long sum = mid * (mid + 1) / 2;
            if(sum == n) { System.out.println(mid); return; }
            else if(sum < n) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println(high);
    }
}
