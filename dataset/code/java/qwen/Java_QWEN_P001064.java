import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int q = sc.nextInt();
        
        Set<String> edges = new HashSet<>();
        for(int i=0; i<m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            edges.add(u + "," + v);
        }
        
        for(int i=0; i<q; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            System.out.println(edges.contains(u + "," + v) ? "YES" : "NO");
        }
    }
}
