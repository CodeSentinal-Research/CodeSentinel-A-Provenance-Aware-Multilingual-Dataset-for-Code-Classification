import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        splitFib(s, 0, new ArrayList<>());
    }
    
    static void splitFib(String s, int idx, List<Long> curr) {
        if(idx == s.length()) {
            if(curr.size() >= 3) {
                System.out.println(curr);
            }
            return;
        }
        
        long num = 0;
        for(int i=idx; i<s.length(); i++) {
            if(i > idx && s.charAt(idx) == '0') break;
            num = num * 10 + (s.charAt(i) - '0');
            if(num > Integer.MAX_VALUE) break;
            
            if(curr.size() < 2 || num == curr.get(curr.size()-1) + curr.get(curr.size()-2)) {
                curr.add(num);
                splitFib(s, i+1, curr);
                curr.remove(curr.size()-1);
            }
        }
    }
}
