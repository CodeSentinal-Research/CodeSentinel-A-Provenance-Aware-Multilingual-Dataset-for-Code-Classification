import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine().trim());
        String[] heightsStr = br.readLine().trim().split(" ");
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = Integer.parseInt(heightsStr[i]);
        }

        int[] result = visiblePeople(n, heights);
        for (int i = 0; i < n; i++) {
            pw.print(result[i] + " ");
        }

        pw.flush();
    }

    public static int[] visiblePeople(int n, int[] heights) {
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && heights[i] > heights[stack.peek()]) {
                result[i]++;
                if (!stack.isEmpty() && heights[i] > heights[stack.peek()]) {
                    result[i] += result[stack.pop()];
                }
            }
            stack.push(i);
        }

        return result;
    }
}
