import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] startWords = new String[n];
        String[] targetWords = new String[m];
        for(int i=0; i<n; i++) startWords[i] = sc.next();
        for(int i=0; i<m; i++) targetWords[i] = sc.next();
        
        Set<Integer> startMasks = new HashSet<>();
        for(String w : startWords) {
            int mask = 0;
            for(char c : w.toCharArray()) mask |= (1 << (c - 'a'));
            startMasks.add(mask);
        }
        
        int count = 0;
        for(String w : targetWords) {
            int mask = 0;
            for(char c : w.toCharArray()) mask |= (1 << (c - 'a'));
            
            for(int i=0; i<26; i++) {
                if((mask & (1 << i)) != 0) {
                    int prevMask = mask ^ (1 << i);
                    if(startMasks.contains(prevMask)) {
                        count++;
                        break;
                    }
                }
            }
        }
        System.out.println(count);
    }
}
