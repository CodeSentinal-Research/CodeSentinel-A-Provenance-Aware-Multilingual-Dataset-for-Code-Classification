import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        int[] start = new int[n];
        int[] end = new int[n];

        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().split(" ");
            start[i] = Integer.parseInt(s[0]);
            end[i] = Integer.parseInt(s[1]);
        }

        Arrays.sort(start);
        Arrays.sort(end);

        int arrows = 1;
        int endPoint = end[0];

        for (int i = 1; i < n; i++) {
            if (start[i] > endPoint) {
                arrows++;
                endPoint = end[i];
            }
        }

        out.println(arrows);
        out.flush();
    }
}
