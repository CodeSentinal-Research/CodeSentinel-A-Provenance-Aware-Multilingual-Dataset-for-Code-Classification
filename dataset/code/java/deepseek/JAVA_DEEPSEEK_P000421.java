import java.util.*;
import java.time.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        List<Membership> memberships = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = scanner.nextLine().split(" ");
            String name = parts[0];
            LocalDate expiryDate = LocalDate.parse(parts[1]);
            memberships.add(new Membership(name, expiryDate));
        }
        LocalDate currentDate = LocalDate.parse(scanner.nextLine());
        for (Membership membership : memberships) {
            if (membership.isExpired(currentDate)) {
                System.out.println(membership.getName());
            }
        }
    }
}

class Membership {
    private String name;
    private LocalDate expiryDate;

    public Membership(String name, LocalDate expiryDate) {
        this.name = name;
        this.expiryDate = expiryDate;
    }

    public String getName() {
        return name;
    }

    public boolean isExpired(LocalDate currentDate) {
        return currentDate.isAfter(expiryDate);
    }
}
