import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        Set<String> dict = new HashSet<>();
        for(int i=0; i<n; i++) dict.add(sc.next());
        List<String> res = new ArrayList<>();
        backtrack(s, dict, new ArrayList<>(), res);
        for (String sentence : res) System.out.println(sentence);
    }
    static void backtrack(String s, Set<String> dict, List<String> current, List<String> res) {
        if (s.isEmpty()) {
            res.add(String.join(" ", current));
            return;
        }
        for (int i = 1; i <= s.length(); i++) {
            String prefix = s.substring(0, i);
            if (dict.contains(prefix)) {
                current.add(prefix);
                backtrack(s.substring(i), dict, current, res);
                current.remove(current.size() - 1);
            }
        }
    }
}
