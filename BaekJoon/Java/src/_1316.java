import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class _1316 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int answer = 0;
        int N = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < N; ++i) {
            int[] alphabet = new int[26];
            Boolean isGroupWord = true;
            String S = br.readLine();

            alphabet[S.charAt(0) - 'a']++;
            for (int j = 1; j < S.length(); ++j) {
                if (S.charAt(j) != S.charAt(j - 1))
                    alphabet[S.charAt(j - 1) - 'a'] = -1;

                if (alphabet[S.charAt(j) - 'a'] < 0)
                    isGroupWord = false;
                
                alphabet[S.charAt(j) - 'a']++;
            }

            if (isGroupWord)
                answer++;
        }

        bw.write(String.valueOf(answer));
        bw.flush();
        bw.close();
    }
}
