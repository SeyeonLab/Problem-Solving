import java.util.Scanner;

public class _10809 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();

        int[] location = new int[26];
        for (int i = 0; i < 26; ++i) location[i] = -1;
        for (int i = 0; i < S.length(); ++i) {
            if (location[S.charAt(i) - 'a'] < 0)
                location[S.charAt(i) - 'a'] = i;
        }

        for (int i = 0; i < 26; ++i)
            System.out.print(location[i] + " ");

        scanner.close();
    }    
}
