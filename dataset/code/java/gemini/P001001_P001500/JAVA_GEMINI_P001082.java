import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[] deg = new int[n];
            int[][] edges = new int[m][2];
            for (int i = 0; i < m; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
                deg[edges[i][0]]++;
                deg[edges[i][1]]++;
            }
            List<Integer> odd = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (deg[i] % 2 != 0) odd.add(i);
            }
            if (odd.size() != 0 && odd.size() != 2) {
                System.out.println("NONE");
            } else {
                int start = odd.size() == 2 ? odd.get(0) : 0;
                boolean[] used = new boolean[m];
                Stack<Integer> stack = new Stack<>();
                List<Integer> path = new ArrayList<>();
                stack.push(start);

                while (!stack.isEmpty()) {
                    int u = stack.peek();
                    int eIdx = -1;
                    for (int i = 0; i < m; i++) {
                        if (!used[i] && (edges[i][0] == u || edges[i][1] == u)) {
                            eIdx = i;
                            break;
                        }
                    }
                    if (eIdx != -1) {
                        used[eIdx] = true;
                        int next = (edges[eIdx][0] == u) ? edges[eIdx][1] : edges[eIdx][0];
                        stack.push(next);
                    } else {
                        path.add(stack.pop());
                    }
                }
                Collections.reverse(path);
                for (int i = 0; i < path.size(); i++) {
                    System.out.print(path.get(i) + (i == path.size() - 1 ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}