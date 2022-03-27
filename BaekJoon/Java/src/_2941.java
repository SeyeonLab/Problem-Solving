import java.util.Scanner;

public class _2941 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();
        int idx = 0;
        int count = 0;

        while (idx < word.length()) {
            if ((word.charAt(idx) == 'c') && (idx < word.length() - 1) && (word.charAt(idx+1) == '=')) {
                idx += 2;
                count++;
                continue;
            }
            else if ((word.charAt(idx) == 'c') && (idx < word.length() - 1) && (word.charAt(idx+1) == '-')) {
                idx += 2;
                count++;
                continue;
            }
            else if ((word.charAt(idx) == 'd') && (idx < word.length() - 2) && (word.charAt(idx+1) == 'z') && (word.charAt(idx+2) == '=')) {
                idx += 3;
                count++;
                continue;
            }
            else if ((word.charAt(idx) == 'd') && (idx < word.length() - 1) && (word.charAt(idx+1) == '-')) {
                idx += 2;
                count++;
                continue;
            }
            else if ((word.charAt(idx) == 'l') && (idx < word.length() - 1) && (word.charAt(idx+1) == 'j')) {
                idx += 2;
                count++;
                continue;
            }
            else if ((word.charAt(idx) == 'n') && (idx < word.length() - 1) && (word.charAt(idx+1) == 'j')) {
                idx += 2;
                count++;
                continue;
            }
            else if ((word.charAt(idx) == 's') && (idx < word.length() - 1) && (word.charAt(idx+1) == '=')) {
                idx += 2;
                count++;
                continue;
            }
            else if ((word.charAt(idx) == 'z') && (idx < word.length() - 1) && (word.charAt(idx+1) == '=')) {
                idx += 2;
                count++;
                continue;
            }
            else {
                idx++;
                count++;
            }
        }

        System.out.print(count);
        scanner.close();
    }    
}
