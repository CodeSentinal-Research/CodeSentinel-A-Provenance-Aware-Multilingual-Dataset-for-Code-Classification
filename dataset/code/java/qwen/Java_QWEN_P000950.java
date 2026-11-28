import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] phi = new int[n+1];
        for(int i=1; i<=n; i++) phi[i] = i;
        
        for(int i=2; i<=n; i++) {
            if(phi[i] == i) { // Prime
                for(int j=i; j<=n; j+=i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }
        for(int i=1; i<=n; i++) System.out.print(phi[i] + " ");
    }
}
