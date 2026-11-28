import java.util.*;
public class Main {
    static int n;
    static int[] res;
    static boolean[] used;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        res = new int[2*n-1];
        used = new boolean[n+1];
        
        backtrack(0);
        
        for(int x : res) System.out.print(x + " ");
    }
    
    static boolean backtrack(int idx) {
        if(idx == 2*n-1) return true;
        if(res[idx] != 0) return backtrack(idx+1);
        
        for(int i=n; i>=1; i--) {
            if(used[i]) continue;
            if(i == 1) {
                res[idx] = 1;
                used[1] = true;
                if(backtrack(idx+1)) return true;
                res[idx] = 0;
                used[1] = false;
            } else {
                int nextIdx = idx + i;
                if(nextIdx < 2*n-1 && res[nextIdx] == 0) {
                    res[idx] = i;
                    res[nextIdx] = i;
                    used[i] = true;
                    if(backtrack(idx+1)) return true;
                    res[idx] = 0;
                    res[nextIdx] = 0;
                    used[i] = false;
                }
            }
        }
        return false;
    }
}
