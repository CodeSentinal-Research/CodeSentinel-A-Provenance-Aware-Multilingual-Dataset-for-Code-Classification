import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input1 = br.readLine().split(" ");
        int m = Integer.parseInt(input1[0]);
        int n = Integer.parseInt(input1[1]);

        String[] input2 = br.readLine().split(" ");
        String[] input3 = br.readLine().split(" ");

        Set<Integer> set = new HashSet<>();
        for (String s : input2) {
            set.add(Integer.parseInt(s));
        }
        for (String s : input3) {
            set.add(Integer.parseInt(s));
       }
        for (int num : set) {
            System.out.print(num + " ");
        }
    }
}
