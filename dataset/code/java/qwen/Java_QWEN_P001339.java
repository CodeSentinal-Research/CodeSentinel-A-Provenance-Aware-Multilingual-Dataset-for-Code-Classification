import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        
        int maxLen = 0;
        // Bitmask DP or Backtracking
        // Since N is small (16), we can use backtracking with pruning
        int[] masks = new int[n];
        for(int i=0; i<n; i++) {
            int mask = 0;
            boolean unique = true;
            for(char c : words[i].toCharArray()) {
                if((mask & (1 << (c-'a'))) != 0) { unique = false; break; }
                mask |= (1 << (c-'a'));
            }
            if(unique) masks[i] = mask;
            else masks[i] = -1;
        }
        
        System.out.println(backtrack(words, masks, 0, 0, 0));
    }
    
    static int backtrack(String[] words, int[] masks, int idx, int currMask, int currLen) {
        if(idx == words.length) return currLen;
        
        int res = backtrack(words, masks, idx+1, currMask, currLen);
        
        if(masks[idx] != -1 && (currMask & masks[idx]) == 0) {
            res = Math.max(res, backtrack(words, masks, idx+1, currMask | masks[idx], currLen + words[idx].length()));
        }
        return res;
    }
}
