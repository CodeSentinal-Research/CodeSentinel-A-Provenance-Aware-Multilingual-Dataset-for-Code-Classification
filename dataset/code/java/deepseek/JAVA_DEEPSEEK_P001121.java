import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            String[] line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]) - 1;
            int b = Integer.parseInt(line[1]) - 1;
            graph[a].add(b);
            graph[b].add(a);
        }
        List<Integer> roots = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                roots.add(i);
            }
        }
        Collections.sort(roots);
        for (int root : roots) {
            out.println(root + 1);
        }
        out.close();
    }
}
