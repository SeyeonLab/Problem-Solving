import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

public class _2908 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        String temp1 = st.nextToken();
        StringBuffer sb1 = new StringBuffer(temp1);
        String num1 = sb1.reverse().toString();
        String temp2 = st.nextToken();
        StringBuffer sb2 = new StringBuffer(temp2);
        String num2 = sb2.reverse().toString();

        if (num1.compareTo(num2) > 0) bw.write(num1);
        else bw.write(num2);

        bw.flush();
        bw.close();
    }
}
