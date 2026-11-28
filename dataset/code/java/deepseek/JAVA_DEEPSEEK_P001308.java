import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int W = scanner.nextInt();
        int H = scanner.nextInt();
        int N = scanner.nextInt();

        int maxArea = 0;
        int[][] defenseTowers = new int[N][2];

        for (int i = 0; i < N; i++) {
            defenseTowers[i] = new int[]{scanner.nextInt(), scanner.nextInt()};
        }

        Arrays.sort(defenseTowers, (a, b) -> a[0] - b[0]);

        int left = W;
        int right = 0;
        int top = H;
        int bottom = 0;

        for (int[] defenseTower : defenseTowers) {
            int x = defenseTower[0];
            int y = defenseTower[1];

            if (x > right) {
                right = x;
            }

            if (y < top) {
                top = y;
            }

            if (x < left) {
                left = x;
            }

            if (y > bottom) {
                bottom = y;
            }
        }

        if (right - left > 0 && top - bottom > 0) {
            maxArea = (right - left) * (top - bottom);
        }

        System.out.println(maxArea);
    }
}
