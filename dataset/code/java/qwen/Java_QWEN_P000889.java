import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(n < 2) { System.out.println("false"); return; }
        for(long i=2; i*i<=n; i++) {
            if(n % i == 0) { System.out.println("false"); return; }
        }
        System.out.println("true");
    }
}
