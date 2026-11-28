import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int p = sc.nextInt();
        
        // Store sparse matrices as lists of non-zero elements
        List<int[]> a = new ArrayList<>();
        List<int[]> b = new ArrayList<>();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int val = sc.nextInt();
                if(val != 0) a.add(new int[]{i, j, val});
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<p; j++) {
                int val = sc.nextInt();
                if(val != 0) b.add(new int[]{i, j, val});
            }
        }
        
        Map<String, Long> resMap = new HashMap<>();
        for(int[] ea : a) {
            for(int[] eb : b) {
                if(ea[1] == eb[0]) {
                    String key = ea[0] + "," + eb[1];
                    resMap.put(key, resMap.getOrDefault(key, 0L) + (long)ea[2] * eb[2]);
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<p; j++) {
                System.out.print(resMap.getOrDefault(i + "," + j, 0L) + " ");
            }
            System.out.println();
        }
    }
}
