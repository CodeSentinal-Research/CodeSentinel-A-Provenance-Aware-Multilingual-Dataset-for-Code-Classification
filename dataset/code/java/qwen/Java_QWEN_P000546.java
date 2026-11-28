import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int minJump = sc.nextInt();
        int maxJump = sc.nextInt();
        int n = s.length();
        
        boolean[] canReach = new boolean[n];
        canReach[0] = true;
        int furthest = 0;
        for(int i=0; i<n; i++) {
            if(!canReach[i]) continue;
            int start = Math.max(i + minJump, furthest + 1);
            int end = Math.min(i + maxJump, n - 1);
            for(int j=start; j<=end; j++) {
                if(s.charAt(j) == '0') {
                    canReach[j] = true;
                    if(j == n - 1) { System.out.println("true"); return; }
                }
            }
            furthest = Math.max(furthest, end);
        }
        System.out.println(canReach[n-1] ? "true" : "false");
    }
}
