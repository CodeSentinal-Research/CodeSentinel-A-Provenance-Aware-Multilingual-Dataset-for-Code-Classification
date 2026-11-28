import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int carpetLen = sc.nextInt();
        int[][] tiles = new int[n][2];
        for(int i=0; i<n; i++) {
            tiles[i][0] = sc.nextInt();
            tiles[i][1] = sc.nextInt();
        }
        
        Arrays.sort(tiles, (a, b) -> a[0] - b[0]);
        
        long[] prefix = new long[n+1];
        for(int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
        }
        
        int maxCovered = 0;
        int j = 0;
        for(int i=0; i<n; i++) {
            long endPos = (long)tiles[i][0] + carpetLen - 1;
            while(j < n && tiles[j][0] <= endPos) j++;
            
            int covered = (int)(prefix[j] - prefix[i]);
            if(j < n) {
                long overlap = Math.max(0, endPos - tiles[j][0] + 1);
                covered -= overlap;
            }
            maxCovered = Math.max(maxCovered, covered);
        }
        System.out.println(maxCovered);
    }
}
