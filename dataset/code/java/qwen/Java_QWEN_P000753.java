import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int target = sc.nextInt();
        subSumAll(arr, 0, 0, target, new ArrayList<>());
    }
    static void subSumAll(int[] arr, int i, int sum, int target, List<Integer> res) {
        if(i == arr.length) {
            if(sum == target) System.out.println(res);
            return;
        }
        res.add(arr[i]);
        subSumAll(arr, i + 1, sum + arr[i], target, res);
        res.remove(res.size() - 1);
        subSumAll(arr, i + 1, sum, target, res);
    }
}
