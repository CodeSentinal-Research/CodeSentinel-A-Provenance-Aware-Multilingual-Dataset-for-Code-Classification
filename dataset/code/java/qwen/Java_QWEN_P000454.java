import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] pages = new int[n];
        for(int i=0; i<n; i++) pages[i] = sc.nextInt();
        
        int low = Arrays.stream(pages).max().getAsInt();
        int high = Arrays.stream(pages).sum();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canAllocate(pages, m, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canAllocate(int[] pages, int m, int limit) {
        int students = 1, sum = 0;
        for(int p : pages) {
            if(sum + p > limit) { students++; sum = p; }
            else sum += p;
        }
        return students <= m;
    }
}
