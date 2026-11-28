import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] sticks = new int[n];
        long sum = 0;
        for(int i=0; i<n; i++) {
            sticks[i] = sc.nextInt();
            sum += sticks[i];
        }
        if(sum % 4 != 0) { System.out.println("false"); return; }
        long side = sum / 4;
        Arrays.sort(sticks);
        long[] sides = new long[4];
        System.out.println(canSquare(sticks, n - 1, sides, side) ? "true" : "false");
    }
    static boolean canSquare(int[] sticks, int idx, long[] sides, long target) {
        if(idx < 0) return true;
        for(int i=0; i<4; i++) {
            if(sides[i] + sticks[idx] <= target) {
                sides[i] += sticks[idx];
                if(canSquare(sticks, idx - 1, sides, target)) return true;
                sides[i] -= sticks[idx];
            }
            if(sides[i] == 0) break;
        }
        return false;
    }
}
