import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long budget = sc.nextLong();
        int[] chargeTimes = new int[n];
        int[] runningCosts = new int[n];
        for(int i=0; i<n; i++) chargeTimes[i] = sc.nextInt();
        for(int i=0; i<n; i++) runningCosts[i] = sc.nextInt();
        
        int maxRobots = 0;
        long sumRunning = 0;
        Deque<Integer> maxCharge = new ArrayDeque<>();
        int left = 0;
        
        for(int right=0; right<n; right++) {
            sumRunning += runningCosts[right];
            while(!maxCharge.isEmpty() && chargeTimes[maxCharge.peekLast()] <= chargeTimes[right]) maxCharge.pollLast();
            maxCharge.offerLast(right);
            
            while(left <= right && chargeTimes[maxCharge.peekFirst()] + (right - left + 1) * sumRunning > budget) {
                sumRunning -= runningCosts[left];
                if(maxCharge.peekFirst() == left) maxCharge.pollFirst();
                left++;
            }
            maxRobots = Math.max(maxRobots, right - left + 1);
        }
        System.out.println(maxRobots);
    }
}
