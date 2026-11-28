import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m1 = sc.nextInt();
        int m2 = sc.nextInt();
        
        int[] deg1 = new int[n+1];
        int[] deg2 = new int[n+1];
        
        for(int i=0; i<m1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            deg1[u]++;
            deg1[v]++;
        }
        
        for(int i=0; i<m2; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            deg2[u]++;
            deg2[v]++;
        }
        
        Arrays.sort(deg1);
        Arrays.sort(deg2);
        
        boolean iso = true;
        for(int i=1; i<=n; i++) {
            if(deg1[i] != deg2[i]) iso = false;
        }
        
        System.out.println(iso ? "YES" : "NO");
    }
}
