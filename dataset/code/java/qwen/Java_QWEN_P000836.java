import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] position = new int[n];
        for(int i=0; i<n; i++) position[i] = sc.nextInt();
        int m = sc.nextInt();
        Arrays.sort(position);
        
        int low = 1, high = position[n-1] - position[0];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canPlace(position, m, mid)) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println(high);
    }
    static boolean canPlace(int[] pos, int m, int dist) {
        int count = 1, lastPos = pos[0];
        for(int i=1; i<pos.length; i++) {
            if(pos[i] - lastPos >= dist) {
                count++;
                lastPos = pos[i];
                if(count == m) return true;
            }
        }
        return false;
    }
}
