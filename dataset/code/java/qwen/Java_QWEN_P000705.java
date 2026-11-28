import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        genSubArr(arr, 0, new ArrayList<>());
    }
    static void genSubArr(int[] arr, int i, List<Integer> curr) {
        if(i == arr.length) {
            System.out.println(curr);
            return;
        }
        genSubArr(arr, i + 1, curr);
        curr.add(arr[i]);
        genSubArr(arr, i + 1, curr);
        curr.remove(curr.size() - 1);
    }
}
