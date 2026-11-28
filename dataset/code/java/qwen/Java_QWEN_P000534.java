import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String senate = sc.next();
        Queue<Integer> radiant = new LinkedList<>();
        Queue<Integer> dire = new LinkedList<>();
        
        for(int i=0; i<senate.length(); i++) {
            if(senate.charAt(i) == 'R') radiant.offer(i);
            else dire.offer(i);
        }
        
        while(!radiant.isEmpty() && !dire.isEmpty()) {
            int r = radiant.poll();
            int d = dire.poll();
            if(r < d) radiant.offer(r + senate.length());
            else dire.offer(d + senate.length());
        }
        System.out.println(radiant.isEmpty() ? "Dire" : "Radiant");
    }
}
