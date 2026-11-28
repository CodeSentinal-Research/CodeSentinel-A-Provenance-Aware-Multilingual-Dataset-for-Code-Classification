import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int m = sc.nextInt();
        String[] words = new String[m];
        for(int i=0; i<m; i++) words[i] = sc.next();
        
        List<Integer> res = new ArrayList<>();
        if(words.length == 0 || s.length() < words[0].length() * words.length) {
            for(int x : res) System.out.print(x + " ");
            if(res.isEmpty()) System.out.println("-1");
            return;
        }
        
        int wordLen = words[0].length();
        int totalLen = wordLen * words.length;
        Map<String, Integer> wordCount = new HashMap<>();
        for(String w : words) wordCount.put(w, wordCount.getOrDefault(w, 0) + 1);
        
        for(int i=0; i<=s.length()-totalLen; i++) {
            Map<String, Integer> seen = new HashMap<>();
            int j = 0;
            while(j < words.length) {
                String word = s.substring(i + j*wordLen, i + (j+1)*wordLen);
                if(!wordCount.containsKey(word)) break;
                seen.put(word, seen.getOrDefault(word, 0) + 1);
                if(seen.get(word) > wordCount.get(word)) break;
                j++;
            }
            if(j == words.length) res.add(i);
        }
        
        if(res.isEmpty()) System.out.println("-1");
        else {
            for(int x : res) System.out.print(x + " ");
        }
    }
}
