import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int h = sc.nextInt();
        int[] piles = new int[n];
        for(int i=0; i<n; i++) piles[i] = sc.nextInt();
        
        int low = 1, high = Arrays.stream(piles).max().getAsInt();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canEat(piles, h, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canEat(int[] piles, int h, int k) {
        int hours = 0;
        for(int p : piles) hours += (p + k - 1) / k;
        return hours <= h;
    }
}
