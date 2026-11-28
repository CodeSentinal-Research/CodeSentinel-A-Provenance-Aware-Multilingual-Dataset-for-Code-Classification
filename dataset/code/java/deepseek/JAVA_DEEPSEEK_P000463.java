import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] sizes = br.readLine().split(" ");
        int[] size = new int[3];
        for (int i = 0; i < 3; i++) {
            size[i] = Integer.valueOf(sizes[i]);
        }

        int[][] arrays = new int[3][size[0]];
        for (int i = 0; i < 3; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < size[i]; j++) {
                arrays[i][j] = Integer.valueOf(line[j]);
            }
       }

        ArrayList<Integer> common = findCommon(arrays[0], arrays[1], arrays[2]);
        for (int num : common) {
            System.out.print(num + " ");
        }
    }

    public static ArrayList<Integer> findCommon(int[] a, int[] b, int[] c) {
        ArrayList<Integer> common = new ArrayList<>();
        int i = 0, j = 0, k = 0;

        while (i < a.length && j < b.length && k < c.length) {
            if (a[i] == b[j] && b[j] == c[k]) {
                common.add(a[i]);
                i++;
                j++;
                k++;
            } else if (a[i] < b[j]) {
                i++;
            } else if (b[j] < c[k]) {
                j++;
            } else {
                k++;
            }
        }

        return common;
    }
}
