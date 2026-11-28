import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long next = n + 1;
        while(true) {
            boolean prime = true;
            for(long i=2; i*i<=next; i++) {
                if(next % i == 0) { prime = false; break; }
            }
            if(prime) { System.out.println(next); return; }
            next++;
        }
    }
}
