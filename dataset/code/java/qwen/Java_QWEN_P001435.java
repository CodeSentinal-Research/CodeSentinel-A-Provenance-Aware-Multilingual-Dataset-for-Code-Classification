import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words1 = new String[n];
        for(int i=0; i<n; i++) words1[i] = sc.next();
        
        int m = sc.nextInt();
        String[] words2 = new String[m];
        for(int i=0; i<m; i++) words2[i] = sc.next();
        
        Map<String, Integer> freq1 = new HashMap<>();
        Map<String, Integer> freq2 = new HashMap<>();
        
        for(String w : words1) freq1.put(w, freq1.getOrDefault(w, 0) + 1);
        for(String w : words2) freq2.put(w, freq2.getOrDefault(w, 0) + 1);
        
        int count = 0;
        for(String w : freq1.keySet()) {
            if(freq1.get(w) == 1 && freq2.getOrDefault(w, 0) == 1) {
                count++;
            }
        }
        System.out.println(count);
    }
}
