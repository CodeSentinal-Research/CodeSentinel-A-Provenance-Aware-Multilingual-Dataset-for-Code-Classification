import java.io.*;
import java.util.*;

public class Main {
    static class Member {
        String name;
        String membershipId;

        Member(String name, String membershipId) {
            this.name = name;
            this.membershipId = membershipId;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Member> members = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            members.add(new Member(input[0], input[1]));
        }
        String searchId = br.readLine();
        boolean found = false;
        for (Member member : members) {
            if (member.membershipId.equals(searchId)) {
                System.out.println(member.name + " " + member.membershipId);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Member Not Found");
        }
    }
}
