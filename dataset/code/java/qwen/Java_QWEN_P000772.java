import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int e = sc.nextInt();
        int f = sc.nextInt();
        System.out.println(eggDrop(e, f));
    }
    static int eggDrop(int e, int f) {
        if(f == 0 || f == 1) return f;
        if(e == 1) return f;
        int min = Integer.MAX_VALUE;
        for(int k=1; k<=f; k++) {
            int res = Math.max(eggDrop(e-1, k-1), eggDrop(e, f-k));
            min = Math.min(min, res);
        }
        return min + 1;
    }
}
