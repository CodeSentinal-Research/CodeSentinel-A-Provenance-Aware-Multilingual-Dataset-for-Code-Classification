import java.util.*;
public class Main {
    static int n, count;
    static boolean[] used;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        used = new boolean[n + 1];
        backtrack(1);
        System.out.println(count);
    }
    static void backtrack(int pos) {
        if(pos > n) {
            count++;
            return;
        }
        for(int i=1; i<=n; i++) {
            if(!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true;
                backtrack(pos + 1);
                used[i] = false;
            }
        }
    }
}
