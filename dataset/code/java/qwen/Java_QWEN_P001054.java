import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for(int i=0; i<n; i++) a[i] = sc.nextInt();
        for(int i=0; i<n; i++) b[i] = sc.nextInt();
        
        Arrays.sort(a);
        Arrays.sort(b);
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]);
        pq.offer(new int[]{a[n-1] + b[n-1], n-1, n-1});
        
        Set<String> visited = new HashSet<>();
        visited.add((n-1) + "," + (n-1));
        
        for(int i=0; i<k; i++) {
            int[] curr = pq.poll();
            System.out.print(curr[0] + " ");
            int ia = curr[1];
            int ib = curr[2];
            
            if(ia > 0 && !visited.contains((ia-1) + "," + ib)) {
                pq.offer(new int[]{a[ia-1] + b[ib], ia-1, ib});
                visited.add((ia-1) + "," + ib);
            }
            if(ib > 0 && !visited.contains(ia + "," + (ib-1))) {
                pq.offer(new int[]{a[ia] + b[ib-1], ia, ib-1});
                visited.add(ia + "," + (ib-1));
            }
        }
    }
}
