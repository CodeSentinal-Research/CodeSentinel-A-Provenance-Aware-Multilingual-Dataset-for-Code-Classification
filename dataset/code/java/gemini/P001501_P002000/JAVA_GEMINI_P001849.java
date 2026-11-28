import java.util.*;

public class Solution {
    private int getHeight(List<Integer> list) {
        if (list.isEmpty()) return 0;
        int root = list.get(0);
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i) < root) left.add(list.get(i));
            else right.add(list.get(i));
        }
        return 1 + Math.max(getHeight(left), getHeight(right));
    }

    public int heightOfBST(int[] preorder) {
        List<Integer> list = new ArrayList<>();
        for (int x : preorder) list.add(x);
        return getHeight(list);
    }
}