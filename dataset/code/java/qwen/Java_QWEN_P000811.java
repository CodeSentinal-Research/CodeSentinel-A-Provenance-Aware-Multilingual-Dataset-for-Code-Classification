import java.util.*;
public class Main {
    // Simulating guess API
    static int secret;
    static int guess(int num) {
        if(num == secret) return 0;
        else if(num > secret) return -1;
        else return 1;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        secret = sc.nextInt(); // In real problem, this is hidden
        
        int low = 1, high = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            if(res == 0) { System.out.println(mid); return; }
            else if(res == -1) high = mid - 1;
            else low = mid + 1;
        }
    }
}
