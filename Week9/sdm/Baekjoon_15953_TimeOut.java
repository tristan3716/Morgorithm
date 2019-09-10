import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

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
public class Baekjoon_15953_TimeOut
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String[] temp  =  scan.nextLine().split(" ");
        int dataSize   = Integer.parseInt(temp[0]);
        int windowSize = Integer.parseInt(temp[1]);
        int[] data = Stream.of(scan.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        List<Integer> result = new ArrayList<>(dataSize);

        IntStream.rangeClosed(1, dataSize)
                 .forEach(idx -> {
                     int start = Math.max(idx - windowSize + 1, 0) != 0 ? idx - windowSize + 1 : 1;
                     int end   = idx;

                     int min = data[start];

                     //[1] 최솟값 찾기
                     for(int i = start-1; i < end; i++) {
                         if (data[i] < min) { min = data[i]; }
                     }

                     result.add(min);
                 });

        System.out.println(result.stream().map(String::valueOf).collect(Collectors.joining(" ")));
    }
}