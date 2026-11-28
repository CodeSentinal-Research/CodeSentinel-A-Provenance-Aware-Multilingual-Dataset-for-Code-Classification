import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(isAdditive(s, 0, new ArrayList<>()) ? "YES" : "NO");
    }
    
    static boolean isAdditive(String s, int idx, List<Long> curr) {
        if(idx == s.length()) return curr.size() >= 3;
        
        long num = 0;
        for(int i=idx; i<s.length(); i++) {
            if(i > idx && s.charAt(idx) == '0') break;
            num = num * 10 + (s.charAt(i) - '0');
            
            if(curr.size() < 2 || num == curr.get(curr.size()-1) + curr.get(curr.size()-2)) {
                curr.add(num);
                if(isAdditive(s, i+1, curr)) return true;
                curr.remove(curr.size()-1);
            }
        }
        return false;
    }
}
