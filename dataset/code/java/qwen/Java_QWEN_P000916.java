import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        long[] der = new long[n+1];
        der[0] = 1;
        if(n >= 1) der[1] = 0;
        for(int i=2; i<=n; i++) {
            der[i] = (i - 1) * (der[i-1] + der[i-2]);
        }
        System.out.println(der[n]);
    }
}
