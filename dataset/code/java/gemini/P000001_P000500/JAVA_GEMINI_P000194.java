import java.util.*;

public class Solution {
    public int NumberofElementsInIntersection(int[] a, int[] b, int n, int m) {
        Set<Integer> setA = new HashSet<>();
        for (int x : a) setA.add(x);
        Set<Integer> setB = new HashSet<>();
        for (int x : b) {
            if (setA.contains(x)) setB.add(x);
        }
        return setB.size();
    }
}