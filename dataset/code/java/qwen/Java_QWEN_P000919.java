import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        
        int even = 0, odd = 0;
        if(n == 0) even = 1;
        while(n > 0) {
            int d = (int)(n % 10);
            if(d % 2 == 0) even++;
            else odd++;
            n /= 10;
        }
        System.out.println(even + " " + odd);
    }
}
