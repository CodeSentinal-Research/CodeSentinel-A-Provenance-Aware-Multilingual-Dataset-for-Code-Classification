import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] quantities = new int[m];
        for(int i=0; i<m; i++) quantities[i] = sc.nextInt();
        
        int low = 1, high = Arrays.stream(quantities).max().getAsInt();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(needStores(quantities, mid) <= n) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static int needStores(int[] quantities, int maxPerStore) {
        int stores = 0;
        for(int q : quantities) {
            stores += (q + maxPerStore - 1) / maxPerStore;
        }
        return stores;
    }
}
