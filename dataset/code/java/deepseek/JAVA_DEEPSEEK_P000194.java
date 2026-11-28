import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input1 = br.readLine().trim().split("\\s+");
        int m = Integer.parseInt(input1[0]);
        int n = Integer.parseInt(input1[1]);
        String[] arr1 = br.readLine().trim().split("\\s+");
        String[] arr2 = br.readLine().trim().split("\\s+");

        Set<String> set1 = new HashSet<>(Arrays.asList(arr1));
        Set<String> set2 = new HashSet<>(Arrays.asList(arr2));

        set1.retainAll(set2);

        System.out.println(String.join(" ", set1));
    }
}
