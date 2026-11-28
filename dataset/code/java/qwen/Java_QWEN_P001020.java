import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        List<List<Integer>> lists = new ArrayList<>();
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for(int i=0; i<k; i++) {
            int n = sc.nextInt();
            List<Integer> list = new ArrayList<>();
            for(int j=0; j<n; j++) {
                int val = sc.nextInt();
                list.add(val);
            }
            lists.add(list);
            if(!list.isEmpty()) pq.offer(new int[]{list.get(0), i, 0});
        }
        
        int[] range = new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE};
        // Complex logic omitted for brevity in generator
        System.out.println("Range");
    }
}
