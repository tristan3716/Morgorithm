/**
 * [ 최솟값 찾기 ]
 * N개의 수 A1, A2, ..., AN과 L이 주어진다.
 *
 * Di = Ai-L+1 ~ Ai 중의 최솟값이라고 할 때,
 * D에 저장된 수를 출력하는 프로그램을 작성하시오.
 *
 * 이때, i ≤ 0 인 Ai는 무시하고 D를 구해야 한다.
 *
 * [입력]
 * 첫째 줄에 N과 L이 주어진다.         (1 ≤ L ≤ N ≤ 5,000,000)
 * 둘째 줄에는 N개의 수 Ai가 주어진다.  (-109 ≤ Ai ≤ 109)
 *
 * [출력]
 * 첫째 줄에 Di를 공백으로 구분하여 순서대로 출력한다.
 *
 * [예제 입력]
 * 12 3
 * 1 5 2 3 6 2 3 7 3 5 2 6
 *
 * [예제 출력]
 * 1 1 1 2 2 2 2 2 3 3 2 2
 *
 * A
 *
 * @author Sight
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Baekjoon_15953
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] temp     = br.readLine().split(" ");

        int dataSize   = Integer.parseInt(temp[0]);
        int windowSize = Integer.parseInt(temp[1]);
        String[] data  = br.readLine().split(" ");

        ArrayDeque<Integer> window = new ArrayDeque<>(windowSize+1);
        int[] windowVal            = new int[dataSize];
        StringBuilder sb           = new StringBuilder(200);

        for (int i = 0 ; i < dataSize; i++ ) {

            int dataInt = Integer.parseInt(data[i]);

            // [1]
            while(!window.isEmpty() && windowVal[window.getLast()] > dataInt)
                window.pollLast();

            // [2]
            window.offer(i);
            windowVal[i] = dataInt;

            // [3]
            if(window.getFirst() <= i - windowSize)
                window.pollFirst();

            sb.append(windowVal[window.getFirst()]).append(" ");
        }

        System.out.println(sb.toString().trim());
    }
}