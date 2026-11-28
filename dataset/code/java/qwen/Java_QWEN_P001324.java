import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        backtrack(k, n, 1, new ArrayList<>());
    }
    
    static void backtrack(int k, int n, int start, List<Integer> curr) {
        if(curr.size() == k) {
            if(n == 0) System.out.println(curr);
            return;
        }
        for(int i=start; i<=9; i++) {
            if(i > n) break;
            curr.add(i);
            backtrack(k, n-i, i+1, curr);
            curr.remove(curr.size()-1);
        }
    }
}
