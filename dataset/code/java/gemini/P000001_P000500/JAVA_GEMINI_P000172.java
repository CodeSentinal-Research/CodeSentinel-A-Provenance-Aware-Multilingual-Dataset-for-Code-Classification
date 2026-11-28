import java.util.*;

public class Solution {
    public void segregateEvenOdd(int[] arr) {
        List<Integer> evens = new ArrayList<>();
        List<Integer> odds = new ArrayList<>();
        for (int x : arr) {
            if (x % 2 == 0) evens.add(x);
            else odds.add(x);
        }
        Collections.sort(evens);
        Collections.sort(odds);
        int idx = 0;
        for (int x : evens) arr[idx++] = x;
        for (int x : odds) arr[idx++] = x;
    }
}