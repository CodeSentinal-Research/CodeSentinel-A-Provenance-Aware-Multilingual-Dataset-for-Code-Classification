import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String pattern = sc.next();
        int n = pattern.length() + 1;
        
        int[] res = new int[n];
        boolean[] used = new boolean[n+1];
        
        backtrack(pattern, 0, res, used);
        
        for(int x : res) System.out.print(x + " ");
    }
    
    static boolean backtrack(String pattern, int idx, int[] res, boolean[] used) {
        if(idx == pattern.length() + 1) return true;
        
        for(int i=1; i<=pattern.length()+1; i++) {
            if(used[i]) continue;
            if(idx > 0) {
                if(pattern.charAt(idx-1) == 'I' && res[idx-1] >= i) continue;
                if(pattern.charAt(idx-1) == 'D' && res[idx-1] <= i) continue;
            }
            
            res[idx] = i;
            used[i] = true;
            if(backtrack(pattern, idx+1, res, used)) return true;
            used[i] = false;
        }
        return false;
    }
}
