import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        int rowIndex = 5;
        List<Integer> row = getRow(rowIndex);
        for (Integer num : row) {
            System.out.print(num + " ");
        }
    }

    public static List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>();
        row.add(1);
        for (int i = 1; i <= rowIndex; i++) {
            row.add((int)(row.get(i - 1) * 1.0 * (rowIndex - i + 1) / i));
        }
        return row;
    }
}
