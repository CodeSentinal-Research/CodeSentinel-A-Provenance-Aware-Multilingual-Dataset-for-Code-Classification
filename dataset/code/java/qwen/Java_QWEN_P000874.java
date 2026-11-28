import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] encoded = new int[n-1];
        for(int i=0; i<n-1; i++) encoded[i] = sc.nextInt();
        
        int totalXor = 0;
        for(int i=1; i<=n; i++) totalXor ^= i;
        
        int oddXor = 0;
        for(int i=1; i<n-1; i+=2) oddXor ^= encoded[i];
        
        int first = totalXor ^ oddXor;
        int[] res = new int[n];
        res[0] = first;
        for(int i=0; i<n-1; i++) {
            res[i+1] = res[i] ^ encoded[i];
        }
        for(int x : res) System.out.print(x + " ");
    }
}
