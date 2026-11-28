import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] pairs = new int[n][2];
        for(int i=0; i<n; i++) {
            pairs[i][0] = sc.nextInt();
            pairs[i][1] = sc.nextInt();
        }
        
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]);
        
        int len = 1;
        int lastEnd = pairs[0][1];
        for(int i=1; i<n; i++) {
            if(pairs[i][0] > lastEnd) {
                len++;
                lastEnd = pairs[i][1];
            }
        }
        System.out.println(len);
    }
}
