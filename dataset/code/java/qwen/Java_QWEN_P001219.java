import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        Set<String> dict = new HashSet<>();
        for(int i=0; i<n; i++) dict.add(sc.next());
        
        List<String> res = new ArrayList<>();
        backtrack(s, dict, new StringBuilder(), res);
        Collections.sort(res);
        for(String sentence : res) System.out.println(sentence);
    }
    
    static void backtrack(String s, Set<String> dict, StringBuilder curr, List<String> res) {
        if(s.isEmpty()) {
            res.add(curr.toString().trim());
            return;
        }
        for(int i=1; i<=s.length(); i++) {
            String prefix = s.substring(0, i);
            if(dict.contains(prefix)) {
                int len = curr.length();
                curr.append(prefix).append(" ");
                backtrack(s.substring(i), dict, curr, res);
                curr.setLength(len);
            }
        }
    }
}
