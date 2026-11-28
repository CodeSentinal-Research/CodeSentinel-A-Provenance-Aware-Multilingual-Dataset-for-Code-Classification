import java.util.*;
public class Main {
    // Simulating isBadVersion API
    static int badVersion;
    static boolean isBadVersion(int version) {
        return version >= badVersion;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        badVersion = sc.nextInt(); // In real problem, this is hidden
        
        int low = 1, high = n;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(isBadVersion(mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
}
