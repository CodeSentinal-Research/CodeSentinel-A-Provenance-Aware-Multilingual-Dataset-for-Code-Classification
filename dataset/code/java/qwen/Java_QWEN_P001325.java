import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        backtrack(n, k, 1, new ArrayList<>());
    }
    
    static void backtrack(int n, int k, int start, List<Integer> curr) {
        if(curr.size() == k) {
            System.out.println(curr);
            return;
        }
        for(int i=start; i<=n; i++) {
            curr.add(i);
            backtrack(n, k, i+1, curr);
            curr.remove(curr.size()-1);
        }
    }
}
