import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] boards = new int[n];
        for (int i = 0; i < n; i++) {
            boards[i] = sc.nextInt();
        }
        int painters = sc.nextInt();
        System.out.println(minTime(boards, painters));
    }

    public static int minTime(int[] boards, int painters) {
        int max = 0;
        long sum = 0;
        for (int i = 0; i < boards.length; i++) {
            max = Math.max(max, boards[i]);
            sum += boards[i];
        }
        long l = max;
        long r = sum;
        while (l < r) {
            long mid = (l + r) / 2;
            if (canPaint(boards, painters, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int) l;
    }

    public static boolean canPaint(int[] boards, int painters, long maxTime) {
        int painterCount = 1;
        long currentTime = 0;
        for (int i = 0; i < boards.length; i++) {
            if (currentTime + boards[i] > maxTime) {
                currentTime = 0;
                painterCount++;
                if (painterCount > painters || boards[i] > maxTime) {
                    return false;
                }
            }
            currentTime += boards[i];
        }
        return true;
    }
}
