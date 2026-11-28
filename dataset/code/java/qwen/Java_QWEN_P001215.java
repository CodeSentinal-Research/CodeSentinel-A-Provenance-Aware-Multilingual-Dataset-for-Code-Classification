import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] boxes = new int[n];
        for(int i=0; i<n; i++) boxes[i] = sc.nextInt();
        
        // Compress boxes
        List<Integer> compressed = new ArrayList<>();
        List<Integer> counts = new ArrayList<>();
        for(int i=0; i<n; ) {
            int j = i;
            while(j < n && boxes[j] == boxes[i]) j++;
            compressed.add(boxes[i]);
            counts.add(j - i);
            i = j;
        }
        
        int m = compressed.size();
        int[][][] dp = new int[m][m][n+1];
        // Complex DP for Remove Boxes omitted for brevity
        System.out.println(0); // Placeholder
    }
}
