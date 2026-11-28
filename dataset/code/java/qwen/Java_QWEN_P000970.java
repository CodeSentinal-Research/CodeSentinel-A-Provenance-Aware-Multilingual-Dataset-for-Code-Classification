import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n == 0) { System.out.println(0); return; }
        if(n <= 2) { System.out.println(1); return; }
        long a = 0, b = 1, c = 1;
        for(int i=3; i<=n; i++) {
            long t = a + b + c;
            a = b;
            b = c;
            c = t;
        }
        System.out.println(c);
    }
}
