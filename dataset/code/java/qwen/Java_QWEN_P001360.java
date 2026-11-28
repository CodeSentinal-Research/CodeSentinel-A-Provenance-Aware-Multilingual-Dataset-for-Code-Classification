import java.util.*;
public class Main {
    static int n;
    static String[] words;
    static int[] letterScores;
    static int[] available;
    static int maxScore;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        
        String availStr = sc.next();
        available = new int[26];
        for(char c : availStr.toCharArray()) available[c-'a']++;
        
        letterScores = new int[26];
        for(int i=0; i<26; i++) letterScores[i] = sc.nextInt();
        
        maxScore = 0;
        backtrack(0, 0, available.clone());
        System.out.println(maxScore);
    }
    
    static void backtrack(int idx, int currScore, int[] currAvail) {
        if(idx == n) {
            maxScore = Math.max(maxScore, currScore);
            return;
        }
        
        // Skip word
        backtrack(idx+1, currScore, currAvail);
        
        // Take word
        int[] temp = currAvail.clone();
        int score = 0;
        boolean canTake = true;
        for(char c : words[idx].toCharArray()) {
            if(temp[c-'a'] <= 0) { canTake = false; break; }
            temp[c-'a']--;
            score += letterScores[c-'a'];
        }
        
        if(canTake) {
            backtrack(idx+1, currScore + score, temp);
        }
    }
}
