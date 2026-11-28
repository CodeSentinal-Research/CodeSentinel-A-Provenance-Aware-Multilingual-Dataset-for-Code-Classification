import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] outDegree = new int[n+1];
        
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            outDegree[u]++;
        }
        
        int count = 0;
        for(int i=1; i<=n; i++) {
            if(outDegree[i] == 0) count++;
        }
        System.out.println(count);
    }
}
