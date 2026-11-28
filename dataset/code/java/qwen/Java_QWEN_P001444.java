import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        
        Map<String, Integer> freq = new HashMap<>();
        for(String w : words) {
            freq.put(w, freq.getOrDefault(w, 0) + 1);
        }
        
        int len = 0;
        for(String w : words) {
            if(w.length() == 2) {
                if(freq.getOrDefault(w, 0) > 1) len += 2;
                else {
                    String rev = new StringBuilder(w).reverse().toString();
                    if(!w.equals(rev) && freq.containsKey(rev)) len += 2;
                }
            } else {
                if(w.charAt(0) == w.charAt(1) && freq.getOrDefault(w, 0) > 1) len += 2;
            }
            freq.put(w, freq.get(w) - 1);
        }
        System.out.println(len);
    }
}
