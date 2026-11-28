import java.util.*;

public class Solution {
    public List<String> getAllAscii() {
        List<String> list = new ArrayList<>();
        for (int i = 0; i < 128; i++) {
            list.add(i + ": " + (char) i);
        }
        return list;
    }
}
