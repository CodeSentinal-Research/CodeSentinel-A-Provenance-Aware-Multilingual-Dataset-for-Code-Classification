import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] encoded = new int[n];
        for(int i=0; i<n; i++) encoded[i] = sc.nextInt();
        int first = sc.nextInt();
        
        int[] res = new int[n+1];
        res[0] = first;
        for(int i=0; i<n; i++) {
            res[i+1] = res[i] ^ encoded[i];
        }
        for(int x : res) System.out.print(x + " ");
    }
}
