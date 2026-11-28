import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] envelopes = new int[n][2];
        for(int i=0; i<n; i++) {
            envelopes[i][0] = sc.nextInt();
            envelopes[i][1] = sc.nextInt();
        }
        
        Arrays.sort(envelopes, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        
        int[] tails = new int[n];
        int len = 0;
        for(int[] e : envelopes) {
            int h = e[1];
            int idx = Arrays.binarySearch(tails, 0, len, h);
            if(idx < 0) idx = -(idx + 1);
            tails[idx] = h;
            if(idx == len) len++;
        }
        System.out.println(len);
    }
}
