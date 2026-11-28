import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long f0 = sc.nextLong();
        long f1 = sc.nextLong();
        int n = sc.nextInt();
        
        if(n == 0) { System.out.println(f0); return; }
        if(n == 1) { System.out.println(f1); return; }
        
        long fn0 = f0, fn1 = f1;
        for(int i=2; i<=n; i++) {
            long fn = a * fn1 + b * fn0;
            fn0 = fn1;
            fn1 = fn;
        }
        System.out.println(fn1);
    }
}
