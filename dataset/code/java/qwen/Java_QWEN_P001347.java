import java.util.*;
public class Main {
    static String w1, w2, w3;
    static Map<Character, Integer> letterToDigit;
    static Set<Character> leadingChars;
    static boolean[] usedDigits;
    static boolean solved;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        w1 = sc.next();
        w2 = sc.next();
        w3 = sc.next();
        
        letterToDigit = new HashMap<>();
        leadingChars = new HashSet<>();
        leadingChars.add(w1.charAt(0));
        leadingChars.add(w2.charAt(0));
        leadingChars.add(w3.charAt(0));
        
        usedDigits = new boolean[10];
        solved = false;
        
        Set<Character> uniqueChars = new LinkedHashSet<>();
        for(char c : (w1+w2+w3).toCharArray()) uniqueChars.add(c);
        
        List<Character> chars = new ArrayList<>(uniqueChars);
        if(chars.size() > 10) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        
        backtrack(chars, 0, new HashMap<>());
        if(!solved) System.out.println("IMPOSSIBLE");
    }
    
    static void backtrack(List<Character> chars, int idx, Map<Character, Integer> mapping) {
        if(solved) return;
        if(idx == chars.size()) {
            if(check(mapping)) {
                solved = true;
                System.out.println(mapping);
            }
            return;
        }
        
        char c = chars.get(idx);
        for(int d=0; d<=9; d++) {
            if(usedDigits[d]) continue;
            if(d == 0 && leadingChars.contains(c)) continue;
            
            usedDigits[d] = true;
            mapping.put(c, d);
            backtrack(chars, idx+1, mapping);
            mapping.remove(c);
            usedDigits[d] = false;
        }
    }
    
    static boolean check(Map<Character, Integer> mapping) {
        long n1 = getVal(w1, mapping);
        long n2 = getVal(w2, mapping);
        long n3 = getVal(w3, mapping);
        return n1 + n2 == n3;
    }
    
    static long getVal(String s, Map<Character, Integer> mapping) {
        long val = 0;
        for(char c : s.toCharArray()) {
            val = val * 10 + mapping.get(c);
        }
        return val;
    }
}
