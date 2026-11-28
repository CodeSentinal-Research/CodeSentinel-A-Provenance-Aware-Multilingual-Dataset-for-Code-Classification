import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        System.out.println(maxLen(words, 0, 0, 0));
    }
    static int maxLen(String[] words, int idx, int mask, int len) {
        if(idx == words.length) return len;
        int res = maxLen(words, idx + 1, mask, len);
        int wMask = getMask(words[idx]);
        if(wMask != -1 && (mask & wMask) == 0) {
            res = Math.max(res, maxLen(words, idx + 1, mask | wMask, len + words[idx].length()));
        }
        return res;
    }
    static int getMask(String s) {
        int mask = 0;
        for(char c : s.toCharArray()) {
            int bit = 1 << (c - 'a');
            if((mask & bit) != 0) return -1;
            mask |= bit;
        }
        return mask;
    }
}
