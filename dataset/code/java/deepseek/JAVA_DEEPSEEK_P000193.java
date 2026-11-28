import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input1 = br.readLine().split(" ");
        int m = Integer.parseInt(input1[0]);
        int n = Integer.parseInt(input1[1]);

        String[] array1 = br.readLine().split(" ");
        String[] array2 = br.readLine().split(" ");

        Set<String> union = new HashSet<>();
        union.addAll(Arrays.asList(array1));
        union.addAll(Arrays.asList(array2));

        for (String element : union) {
            System.out.print(element + " ");
        }
    }
}
