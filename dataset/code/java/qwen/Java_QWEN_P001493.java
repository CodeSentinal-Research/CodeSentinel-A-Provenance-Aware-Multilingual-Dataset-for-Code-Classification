import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        char c = sc.nextLine().charAt(0);
        
        int n = s.length();
        int[] res = new int[n];
        Arrays.fill(res, Integer.MAX_VALUE);
        
        int prev = -n;
        for(int i=0; i<n; i++) {
            if(s.charAt(i) == c) prev = i;
            res[i] = i - prev;
        }
        
        int next = 2*n;
        for(int i=n-1; i>=0; i--) {
            if(s.charAt(i) == c) next = i;
            res[i] = Math.min(res[i], next - i);
        }
        
        for(int x : res) System.out.print(x + " ");
    }
}
