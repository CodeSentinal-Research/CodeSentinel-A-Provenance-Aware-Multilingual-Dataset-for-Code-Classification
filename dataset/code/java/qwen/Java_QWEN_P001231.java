import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] g = new int[n];
        int[] s = new int[m];
        for(int i=0; i<n; i++) g[i] = sc.nextInt();
        for(int i=0; i<m; i++) s[i] = sc.nextInt();
        
        Arrays.sort(g);
        Arrays.sort(s);
        
        int i=0, j=0, count=0;
        while(i<n && j<m) {
            if(g[i] <= s[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        System.out.println(count);
    }
}
