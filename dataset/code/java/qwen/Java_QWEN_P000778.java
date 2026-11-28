import java.util.*;
public class Main {
    static int N;
    static int[] nums;
    static long totalSum;
    static long minDiff;
    static List<Integer> bestSet1;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        nums = new int[N];
        for(int i=0; i<N; i++) {
            nums[i] = sc.nextInt();
            totalSum += nums[i];
        }
        minDiff = Long.MAX_VALUE;
        bestSet1 = new ArrayList<>();
        tugOfWar(0, new ArrayList<>(), 0);
        System.out.println(minDiff);
        System.out.println(bestSet1);
    }
    static void tugOfWar(int idx, List<Integer> set1, long sum1) {
        if(set1.size() == N/2 || set1.size() == (N+1)/2) {
            long diff = Math.abs(totalSum - 2*sum1);
            if(diff < minDiff) {
                minDiff = diff;
                bestSet1 = new ArrayList<>(set1);
            }
            return;
        }
        if(idx == N) return;
        set1.add(nums[idx]);
        tugOfWar(idx + 1, set1, sum1 + nums[idx]);
        set1.remove(set1.size() - 1);
        tugOfWar(idx + 1, set1, sum1);
    }
}
