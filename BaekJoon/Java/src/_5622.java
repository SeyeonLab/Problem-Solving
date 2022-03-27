import java.util.Scanner;

public class _5622 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int sum = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c >= 'A' && c <= 'C') sum += 3;
            else if (c >= 'D' && c <= 'F') sum += 4;
            else if (c >= 'G' && c <= 'I') sum += 5;
            else if (c >= 'J' && c <= 'L') sum += 6;
            else if (c >= 'M' && c <= 'O') sum += 7;
            else if (c >= 'P' && c <= 'S') sum += 8;
            else if (c >= 'T' && c <= 'V') sum += 9;
            else if (c >= 'W' && c <= 'Z') sum += 10;
        }

        System.out.print(sum);
        scanner.close();
    }
}