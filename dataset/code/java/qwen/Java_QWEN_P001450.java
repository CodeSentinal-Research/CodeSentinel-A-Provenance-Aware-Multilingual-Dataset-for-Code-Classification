import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        String[] votes = new String[v];
        for(int i=0; i<v; i++) votes[i] = sc.next();
        
        int n = votes[0].length();
        int[][] count = new int[26][n];
        
        for(String vote : votes) {
            for(int i=0; i<n; i++) {
                count[vote.charAt(i) - 'A'][i]++;
            }
        }
        
        List<Character> teams = new ArrayList<>();
        for(int i=0; i<26; i++) {
            if(count[i][0] > 0) teams.add((char)('A' + i));
        }
        
        teams.sort((a, b) -> {
            for(int i=0; i<n; i++) {
                if(count[a-'A'][i] != count[b-'A'][i]) {
                    return count[b-'A'][i] - count[a-'A'][i];
                }
            }
            return a - b;
        });
        
        StringBuilder sb = new StringBuilder();
        for(char c : teams) sb.append(c);
        System.out.println(sb.toString());
    }
}
