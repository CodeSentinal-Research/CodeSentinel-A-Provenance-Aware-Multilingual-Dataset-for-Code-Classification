import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static class Record {
        String id;
        String description;

        public Record(String id, String description) {
            this.id = id;
            this.description = description;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        List<Record> records = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String id = scanner.next();
            String description = scanner.next();
            records.add(new Record(id, description));
        }

        String keyword = scanner.next();

        for (Record record : records) {
            if (record.description.contains(keyword)) {
                System.out.println(record.id);
            }
        }
    }
}
