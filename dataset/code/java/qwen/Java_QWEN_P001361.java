import java.util.*;
public class Main {
    static String[] stickers;
    static String target;
    static int[] targetCount;
    static Map<String, Integer> memo;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        stickers = new String[n];
        for(int i=0; i<n; i++) stickers[i] = sc.next();
        target = sc.next();
        
        targetCount = new int[26];
        for(char c : target.toCharArray()) targetCount[c-'a']++;
        
        memo = new HashMap<>();
        int res = minStickers(targetCount);
        System.out.println(res == Integer.MAX_VALUE ? -1 : res);
    }
    
    static int minStickers(int[] count) {
        String key = Arrays.toString(count);
        if(memo.containsKey(key)) return memo.get(key);
        
        if(allZero(count)) return 0;
        
        int min = Integer.MAX_VALUE;
        for(String sticker : stickers) {
            int[] stickerCount = new int[26];
            for(char c : sticker.toCharArray()) stickerCount[c-'a']++;
            
            // Optimization: only use sticker if it contains first missing char
            boolean useful = false;
            for(int i=0; i<26; i++) {
                if(count[i] > 0 && stickerCount[i] > 0) {
                    useful = true;
                    break;
                }
            }
            if(!useful) continue;
            
            int[] newCount = count.clone();
            for(int i=0; i<26; i++) {
                newCount[i] = Math.max(0, newCount[i] - stickerCount[i]);
            }
            
            int res = minStickers(newCount);
            if(res != Integer.MAX_VALUE) {
                min = Math.min(min, 1 + res);
            }
        }
        
        memo.put(key, min);
        return min;
    }
    
    static boolean allZero(int[] count) {
        for(int c : count) if(c > 0) return false;
        return true;
    }
}
