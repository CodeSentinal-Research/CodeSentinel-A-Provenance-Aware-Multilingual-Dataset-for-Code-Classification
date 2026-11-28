import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[][] intervals = new int[n][2];
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            intervals[i][0] = Integer.parseInt(line[0]);
            intervals[i][1] = Integer.parseInt(line[1]);
       
            Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
            TreeMap<Integer, Integer> map = new TreeMap<>();
            for (int j = 0; j < n; j++) {
                Map.Entry<Integer, Integer> entry = map.floorEntry(intervals[j][0]);
                if (entry != null && entry.getValue() >= intervals[j][1]) {
                    pw.println(entry.getKey());
                    map.remove(entry.getKey());
                } else {
                    pw.println(-1);
                }
                map.put(j, intervals[j][1]);
            }
            pw.flush();
        }
    }
}
