import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 0) { System.out.println(0); return; }
        if (n == 1 || n == 2) { System.out.println(1); return; }
        
        long[] t = new long[n + 1];
        t[0] = 0; t[1] = 1; t[2] = 1;
        for (int i = 3; i <= n; i++) {
            t[i] = t[i - 1] + t[i - 2] + t[i - 3];
        }
        System.out.println(t[n]);
    }
}
