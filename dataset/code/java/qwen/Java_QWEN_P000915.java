import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        long[] catalan = new long[n+1];
        catalan[0] = 1;
        for(int i=1; i<=n; i++) {
            catalan[i] = 0;
            for(int j=0; j<i; j++) {
                catalan[i] += catalan[j] * catalan[i-1-j];
            }
        }
        System.out.println(catalan[n]);
    }
}
