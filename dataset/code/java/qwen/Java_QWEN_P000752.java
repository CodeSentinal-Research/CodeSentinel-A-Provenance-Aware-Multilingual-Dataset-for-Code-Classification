import java.util.*;
public class Main {
    static boolean found;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int target = sc.nextInt();
        found = false;
        List<Integer> res = new ArrayList<>();
        subSumOne(arr, 0, 0, target, res);
        if(!found) System.out.println(-1);
    }
    static void subSumOne(int[] arr, int i, int sum, int target, List<Integer> res) {
        if(found) return;
        if(i == arr.length) {
            if(sum == target) {
                System.out.println(res);
                found = true;
            }
            return;
        }
        res.add(arr[i]);
        subSumOne(arr, i + 1, sum + arr[i], target, res);
        res.remove(res.size() - 1);
        subSumOne(arr, i + 1, sum, target, res);
    }
}
