import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] boards = new int[n];
        for(int i=0; i<n; i++) boards[i] = sc.nextInt();
        int painters = sc.nextInt();
        
        int low = Arrays.stream(boards).max().getAsInt();
        int high = Arrays.stream(boards).sum();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canPaint(boards, painters, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canPaint(int[] boards, int painters, int time) {
        int p = 1, sum = 0;
        for(int b : boards) {
            if(sum + b > time) { p++; sum = b; }
            else sum += b;
        }
        return p <= painters;
    }
}
