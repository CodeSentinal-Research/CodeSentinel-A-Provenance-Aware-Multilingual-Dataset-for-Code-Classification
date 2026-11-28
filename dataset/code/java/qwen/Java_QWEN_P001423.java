import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        String pattern = sc.next();
        
        List<String> res = new ArrayList<>();
        for(String w : words) {
            if(matches(w, pattern)) res.add(w);
        }
        
        Collections.sort(res);
        for(String w : res) System.out.println(w);
    }
    
    static boolean matches(String word, String pattern) {
        Map<Character, Character> mapWT = new HashMap<>();
        Map<Character, Character> mapTW = new HashMap<>();
        
        for(int i=0; i<word.length(); i++) {
            char w = word.charAt(i);
            char p = pattern.charAt(i);
            
            if(mapWT.containsKey(w) && mapWT.get(w) != p) return false;
            if(mapTW.containsKey(p) && mapTW.get(p) != w) return false;
            
            mapWT.put(w, p);
            mapTW.put(p, w);
        }
        return true;
    }
}
