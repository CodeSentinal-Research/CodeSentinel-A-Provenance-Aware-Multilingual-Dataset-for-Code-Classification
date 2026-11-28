import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String trainNo = sc.next();
            String dest = sc.next();
            map.put(trainNo, dest);
        }
        String searchTrain = sc.next();
        if(map.containsKey(searchTrain)) System.out.println(map.get(searchTrain));
        else System.out.println("Train Not Found");
    }
}
