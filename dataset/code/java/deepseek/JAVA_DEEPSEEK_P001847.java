import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println(minSwaps(arr));
    }

    static int minSwaps(int arr[]) {
        int n = arr.length;
        Pair[] pairs = new Pair[n];
        for (int i = 0; i < n; i++) {
            pairs[i] = new Pair(arr[i], i);
        }
        Arrays.sort(pairs);

        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || pairs[i].index == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pairs[j].index;
                cycleSize++;
            }

            if (cycleSize > 0) {
                ans += (cycleSize - 1);
            }
        }

        return ans;
    }

    static class Pair implements Comparable<Pair> {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }

        public int compareTo(Pair p) {
            return this.value - p.value;
        }
    }
}
