import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] sticks = new int[n];
        for(int i=0; i<n; i++) sticks[i] = sc.nextInt();
        
        long sum = 0;
        for(int s : sticks) sum += s;
        if(sum % 4 != 0) {
            System.out.println("NO");
            return;
        }
        
        long side = sum / 4;
        Arrays.sort(sticks);
        boolean[] used = new boolean[n];
        System.out.println(canForm(sticks, used, 0, 0, side, 0) ? "YES" : "NO");
    }
    
    static boolean canForm(int[] sticks, boolean[] used, int idx, long currSum, long side, int count) {
        if(count == 3) return true;
        if(currSum == side) return canForm(sticks, used, 0, 0, side, count+1);
        
        for(int i=idx; i<sticks.length; i++) {
            if(used[i] || currSum + sticks[i] > side) continue;
            used[i] = true;
            if(canForm(sticks, used, i+1, currSum + sticks[i], side, count)) return true;
            used[i] = false;
        }
        return false;
    }
}
