import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] events = new int[n][2];
        for(int i=0; i<n; i++) {
            events[i][0] = sc.nextInt();
            events[i][1] = sc.nextInt();
        }
        
        Arrays.sort(events, (a, b) -> a[1] - b[1]);
        
        TreeSet<Integer> days = new TreeSet<>();
        for(int i=1; i<=100000; i++) days.add(i);
        
        int count = 0;
        for(int[] event : events) {
            Integer day = days.ceiling(event[0]);
            if(day != null && day <= event[1]) {
                count++;
                days.remove(day);
            }
        }
        System.out.println(count);
    }
}
