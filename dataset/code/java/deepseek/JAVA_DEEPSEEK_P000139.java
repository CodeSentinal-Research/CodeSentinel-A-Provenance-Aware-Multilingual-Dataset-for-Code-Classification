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

        String[] input2 = br.readLine().split(" ");
        String[] input3 = br.readLine().split(" ");

        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();

        for (String s : input2) {
            set1.add(Integer.parseInt(s));
        }

        for (String s : input3) {
            set2.add(Integer.parseInt(s));
        }

        set1.retainAll(set2);

        Integer[] output = set1.toArray(new Integer[0]);
        Arrays.sort(output);

        for (Integer num : output) {
            System.out.println(num);
        }
    }
}
