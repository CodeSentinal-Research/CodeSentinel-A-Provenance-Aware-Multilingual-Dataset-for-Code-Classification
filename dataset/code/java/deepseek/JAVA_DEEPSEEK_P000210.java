import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n1 = Integer.parseInt(br.readLine());
        int n2 = Integer.parseInt(br.readLine());
        int n3 = Integer.parseInt(br.readLine());

        int[] arr1 = new int[n1];
        int[] arr2 = new int[n2];
        int[] arr3 = new int[n3];

        String[] str1 = br.readLine().split(" ");
        String[] str2 = br.readLine().split(" ");
        String[] str3 = br.readLine().split(" ");

        for (int i = 0; i < n1; i++) {
            arr1[i] = Integer.parseInt(str1[i]);
        }

        for (int i = 0; i < n2; i++) {
            arr2[i] = Integer.parseInt(str2[i]);
        }

        for (int i = 0; i < n3; i++) {
            arr3[i] = Integer.parseInt(str3[i]);
        }

        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();

        for (int i = 0; i < n1; i++) {
            set1.add(arr1[i]);
        }

        for (int i = 0; i < n2; i++) {
            if (set1.contains(arr2[i])) {
                set2.add(arr2[i]);
            }
        }

        for (int i = 0; i < n3; i++) {
            if (set2.contains(arr3[i])) {
                System.out.print(arr3[i] + " ");
            }
        }
    }
}
