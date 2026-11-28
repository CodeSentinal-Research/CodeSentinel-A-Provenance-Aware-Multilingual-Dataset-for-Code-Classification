import java.util.*;

public class Main {
    public static void main(String[] args) {
        int[] target = {1, 2, 3, 4, 5};
        int n = 5;
        System.out.println(buildArray(target, n));
    }

    public static List<String> buildArray(int[] target, int n) {
        List<String> result = new ArrayList<>();
        int i = 1;
        int j = 0;
        while (j < target.length) {
            if (i < target[j]) {
                result.add("Push");
                result.add("Pop");
                i++;
            } else {
                result.add("Push");
                i++;
                j++;
           }
        }
        return result;
    }
}
