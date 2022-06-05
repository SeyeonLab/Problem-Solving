import java.util.Scanner;
import java.util.HashSet;

public class _11478 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        HashSet<String> hashSet = new HashSet<>();
        
        for (int i = 1; i <= S.length(); i++) {
            for (int j = 0; j < S.length() - i + 1; j++) {
                hashSet.add(S.substring(j, j + i));
            }
        }
        System.out.println(hashSet.size());
        scanner.close();
    }
}