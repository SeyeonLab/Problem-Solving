import java.util.Scanner;
public class _1157 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();
        int[] alphabet = new int[26];
        
        for (int i = 0; i < word.length(); ++i) {
            char c = word.charAt(i);
            if (c >= 'a' && c <= 'z') {
                alphabet[c - 'a']++;
            }
            else {
                alphabet[c - 'A']++;
            }
        }

        int max = -1;
        int index = 0;
        for (int i = 0; i < 26; ++i) {
            if (alphabet[i] >= max) {
                index = i;
                max = alphabet[i];
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (max == alphabet[i] && index != i) {
                System.out.println("?");
                break;
            }
            else if (alphabet[i] == max) {
                System.out.println((char)(index + 'A'));
            }
        }

        scanner.close();
    }    
}
