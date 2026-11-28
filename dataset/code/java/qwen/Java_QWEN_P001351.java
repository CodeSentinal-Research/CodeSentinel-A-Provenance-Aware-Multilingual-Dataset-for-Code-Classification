import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        
        backtrack(s, k, 0, new ArrayList<>());
    }
    
    static void backtrack(String s, int k, int start, List<String> curr) {
        if(curr.size() == k) {
            System.out.println(curr);
            return;
        }
        for(int i=start; i<s.length(); i++) {
            curr.add(String.valueOf(s.charAt(i)));
            backtrack(s, k, i+1, curr);
            curr.remove(curr.size()-1);
        }
    }
}
