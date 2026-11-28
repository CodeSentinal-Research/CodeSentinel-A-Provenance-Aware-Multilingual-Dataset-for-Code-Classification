import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] pages = new int[n];
        for(int i=0; i<n; i++) pages[i] = sc.nextInt();
        int students = sc.nextInt();
        
        int low = Arrays.stream(pages).max().getAsInt();
        int high = Arrays.stream(pages).sum();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canAllocate(pages, students, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canAllocate(int[] pages, int students, int limit) {
        int s = 1, sum = 0;
        for(int p : pages) {
            if(sum + p > limit) { s++; sum = p; }
            else sum += p;
        }
        return s <= students;
    }
}
