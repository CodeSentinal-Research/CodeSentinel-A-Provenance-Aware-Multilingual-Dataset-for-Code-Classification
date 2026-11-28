import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] h1 = new int[n];
        int[] h2 = new int[m];
        for(int i=0; i<n; i++) h1[i] = sc.nextInt();
        for(int i=0; i<m; i++) h2[i] = sc.nextInt();
        
        if(n != m) System.out.println("NO");
        else {
            boolean same = true;
            for(int i=0; i<n; i++) {
                if(h1[i] != h2[i]) same = false;
            }
            System.out.println(same ? "YES" : "NO");
        }
    }
}
