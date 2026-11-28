import java.util.Arrays;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());
        String[] array1 = new String[n];
        for (int i = 0; i < n; i++) {
            array1[i] = reader.readLine();
        }

        int m = Integer.parseInt(reader.readLine());
        String[] array2 = new String[m];
        for (int i = 0; i < m; i++) {
            array2[i] = reader.readLine();
        }

        System.out.println(Arrays.equals(array1, array2) ? "Yes" : "No");
    }
}
