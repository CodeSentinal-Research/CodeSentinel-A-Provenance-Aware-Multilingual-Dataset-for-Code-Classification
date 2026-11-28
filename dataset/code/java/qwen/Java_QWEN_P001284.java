import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] top = new int[n];
        int[] bottom = new int[n];
        for(int i=0; i<n; i++) top[i] = sc.nextInt();
        for(int i=0; i<n; i++) bottom[i] = sc.nextInt();
        
        int res = Integer.MAX_VALUE;
        for(int val=1; val<=6; val++) {
            int rotationsTop = 0, rotationsBottom = 0;
            boolean possible = true;
            for(int i=0; i<n; i++) {
                if(top[i] != val && bottom[i] != val) {
                    possible = false;
                    break;
                }
                if(top[i] != val) rotationsTop++;
                if(bottom[i] != val) rotationsBottom++;
            }
            if(possible) res = Math.min(res, Math.min(rotationsTop, rotationsBottom));
        }
        System.out.println(res == Integer.MAX_VALUE ? -1 : res);
    }
}
