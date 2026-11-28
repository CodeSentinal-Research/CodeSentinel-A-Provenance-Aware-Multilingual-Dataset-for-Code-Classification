import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        
        Map<String, Integer> freq1 = new HashMap<>();
        Map<String, Integer> freq2 = new HashMap<>();
        
        for(String w : s1.split("\\s+")) freq1.put(w, freq1.getOrDefault(w, 0) + 1);
        for(String w : s2.split("\\s+")) freq2.put(w, freq2.getOrDefault(w, 0) + 1);
        
        List<String> res = new ArrayList<>();
        for(String w : freq1.keySet()) {
            if(freq1.get(w) == 1 && !freq2.containsKey(w)) res.add(w);
        }
        for(String w : freq2.keySet()) {
            if(freq2.get(w) == 1 && !freq1.containsKey(w)) res.add(w);
        }
        
        Collections.sort(res);
        for(String w : res) System.out.print(w + " ");
    }
}
