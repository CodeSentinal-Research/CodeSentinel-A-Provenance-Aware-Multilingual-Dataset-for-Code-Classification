import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long num = sc.nextLong();
        
        long low = 1, high = num;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            if(mid * mid == num) { System.out.println("true"); return; }
            else if(mid * mid < num) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println("false");
    }
}
