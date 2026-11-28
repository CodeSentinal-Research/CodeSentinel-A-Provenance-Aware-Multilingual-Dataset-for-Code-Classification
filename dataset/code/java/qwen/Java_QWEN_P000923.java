import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        boolean[] used = new boolean[10];
        System.out.println(countUnique(n, 0, used));
    }
    static long countUnique(int n, int pos, boolean[] used) {
        if(pos == n) return 1;
        long count = 0;
        int start = (pos == 0) ? 1 : 0;
        for(int i=start; i<=9; i++) {
            if(!used[i]) {
                used[i] = true;
                count += countUnique(n, pos + 1, used);
                used[i] = false;
            }
        }
        return count;
    }
}
