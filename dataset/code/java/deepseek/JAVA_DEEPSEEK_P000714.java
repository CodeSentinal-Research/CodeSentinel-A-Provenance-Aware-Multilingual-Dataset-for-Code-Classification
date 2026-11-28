import java.util.*;

public class Main {
    private static List<Integer> subsetSums(List<Integer> arr, int n) {
        List<Integer> res = new ArrayList<>();
        subsetSumsHelper(arr, n, 0, 0, res);
        Collections.sort(res);
        return res;
    }

    private static void subsetSumsHelper(List<Integer> arr, int n, int index, int sum, List<Integer> res) {
        if (index == n) {
            res.add(sum);
            return;
        }

        subsetSumsHelper(arr, n, index + 1, sum + arr.get(index), res);
        subsetSumsHelper(arr, n, index + 1, sum, res);
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(5, 10, 12, 13, 15, 16);
        List<Integer> res = subsetSums(arr, arr.size());
        for (int sum : res) {
            System.out.print(sum + " ");
        }
    }
}
