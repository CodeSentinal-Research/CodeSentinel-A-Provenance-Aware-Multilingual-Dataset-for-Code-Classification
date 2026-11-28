import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(maxUnique(s, 0, new HashSet<>()));
    }
    
    static int maxUnique(String s, int idx, Set<String> seen) {
        if(idx == s.length()) return 0;
        
        int maxParts = 0;
        for(int i=idx+1; i<=s.length(); i++) {
            String sub = s.substring(idx, i);
            if(!seen.contains(sub)) {
                seen.add(sub);
                maxParts = Math.max(maxParts, 1 + maxUnique(s, i, seen));
                seen.remove(sub);
            }
        }
        return maxParts;
    }
}
