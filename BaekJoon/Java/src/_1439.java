import java.util.Scanner;

public class _1439 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int countZero = 0, countOne = 0;

        for (int i = 0; i < S.length();) {
            if (S.charAt(i) == '0') {
                countZero++;
                while (i < S.length() && S.charAt(i) == '0')
                    i++;
            } else {
                countOne++;
                while (i < S.length() && S.charAt(i) == '1')
                    i++;
            }
        }

        // 0와 1 중에 count 적은 것이 정답
        System.out.println(countZero > countOne ? countOne : countZero);
        scanner.close();
    }
}
