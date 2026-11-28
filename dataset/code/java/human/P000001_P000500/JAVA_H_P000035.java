import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// Perfect number program in java

class PerfectNumberProgram {
 public static void main(String args[]) throws IOException {
 System.out.println("Enter number to check perfect number or not : ");
 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

 int number = Integer.parseInt(br.readLine());
 int sumOfDivisors = 0;

 for (int i = 1; i < number; i++) {
 if (number % i == 0) {
 sumOfDivisors = sumOfDivisors + i;
 }
 }
 if (number == sumOfDivisors) {
 System.out.println(number + " is a perfect number");
 } else {
 System.out.println(number + " is not a perfect number");
 }
 }
 }












/*
👋 Hi, I’m @aarushinair — Aarushi Nair (she/her)
🎓 CS Engineer | AI Researcher | Software Engineer | DEI Professional
💡 Interests: AI/ML/DL, Responsible Tech, Innovative Technologies, Ethics in AI
🌍 Advocate for Women in Tech | Community & Events Manager @AnitaB.org India
🎙️ Speaker | Content Creator | STEM Mentor
📫 Let’s connect: https://www.linkedin.com/in/aarushinair/
📹 YouTube: Code with Aarushi → https://www.youtube.com/channel/UCKj5T1ELHCmkGKujkpqtl7Q
🐦 Twitter/X: https://x.com/aarushinair_
📁 Portfolio, projects & talks: https://github.com/aarushinair
*/
