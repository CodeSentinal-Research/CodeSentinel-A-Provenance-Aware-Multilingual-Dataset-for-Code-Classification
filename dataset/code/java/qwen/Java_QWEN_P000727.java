import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int m = sc.nextInt();
        Set<String> dict = new HashSet<>();
        for(int i=0; i<m; i++) dict.add(sc.next());
        wordBreakII(s, dict, new ArrayList<>());
    }
    static void wordBreakII(String s, Set<String> dict, List<String> curr) {
        if(s.isEmpty()) {
            System.out.println(String.join(" ", curr));
            return;
        }
        for(int i=1; i<=s.length(); i++) {
            String prefix = s.substring(0, i);
            if(dict.contains(prefix)) {
                curr.add(prefix);
                wordBreakII(s.substring(i), dict, curr);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
