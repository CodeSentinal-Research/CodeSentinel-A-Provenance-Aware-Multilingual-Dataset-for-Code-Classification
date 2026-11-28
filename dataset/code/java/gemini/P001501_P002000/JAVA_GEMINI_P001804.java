import java.util.*;

public class Solution {
    public boolean isSameBSTSeq(int[] a, int[] b) {
        if (a.length != b.length) return false;
        if (a.length == 0) return true;
        if (a[0] != b[0]) return false;

        List<Integer> leftA = new ArrayList<>(), rightA = new ArrayList<>();
        List<Integer> leftB = new ArrayList<>(), rightB = new ArrayList<>();

        for (int i = 1; i < a.length; i++) {
            if (a[i] < a[0]) leftA.add(a[i]);
            else rightA.add(a[i]);

            if (b[i] < b[0]) leftB.add(b[i]);
            else rightB.add(b[i]);
        }

        int[] lA = leftA.stream().mapToInt(x -> x).toArray();
        int[] lB = leftB.stream().mapToInt(x -> x).toArray();
        int[] rA = rightA.stream().mapToInt(x -> x).toArray();
        int[] rB = rightB.stream().mapToInt(x -> x).toArray();

        return isSameBSTSeq(lA, lB) && isSameBSTSeq(rA, rB);
    }
}