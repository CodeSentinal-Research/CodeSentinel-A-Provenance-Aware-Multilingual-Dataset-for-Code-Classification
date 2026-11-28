import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        
        int[] common = new int[26];
        Arrays.fill(common, Integer.MAX_VALUE);
        
        for(String w : words) {
            int[] freq = new int[26];
            for(char c : w.toCharArray()) freq[c-'a']++;
            for(int i=0; i<26; i++) common[i] = Math.min(common[i], freq[i]);
        }
        
        List<Character> res = new ArrayList<>();
        for(int i=0; i<26; i++) {
            for(int j=0; j<common[i]; j++) res.add((char)(i+'a'));
        }
        
        for(char c : res) System.out.print(c + " ");
    }
}
