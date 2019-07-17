/**
 * 백준 1325번
 *
 * 해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다.
 * 이 회사는 N개의 컴퓨터로 이루어져 있다.
 * 김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
 *
 * 이 회사의 컴퓨터는 신뢰하는 관계와,
 * 신뢰하지 않는 관계로 이루어져 있는데,
 *
 * A가 B를 신뢰하는 경우에는 B를 해킹하면,
 * A도 해킹할 수 있다는 소리다.
 *
 * 이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때,
 * 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.
 *
 * [입력]
 *  첫째 줄에, N과 M이 들어온다.
 * N은 10,000보다 작거나 같은 자연수,
 * M은 100,000보다 작거나 같은 자연수이다.
 *
 * 둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다.
 * 컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.
 *
 * [출력]
 * 첫째 줄에, 김지민이 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력한다.
 *
 * @author Sight
 * @since  2019. 07 .14
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import java.util.stream.Stream;

class Baekjoon_1325 {
    public static void main(String[] args) throws IOException {

        BufferedReader br       = new BufferedReader(new InputStreamReader(System.in));
        List<String>  container = new ArrayList<>(1000);
        List<Integer> result    = new ArrayList<>();

        // [1] 초기 메타데이터 세팅
        int[] meta = Stream.of(br.readLine().split(" "))
                           .mapToInt(Integer::parseInt)
                           .toArray();

        int size       = meta[0];               // 컴퓨터 개수 ( 0 ~ size )
        int refCnt     = meta[1];               // 간선 개수

        HashMap<Integer, ArrayList<Integer>> matrix = new HashMap<>(size); // 인접행렬 목록

        // [2] 신뢰 관계 input 세팅 인접행렬 세팅
        for( int i = 0; i < refCnt; i++) {
            String[] ref = br.readLine().split(" ");
            int from = Integer.parseInt(ref[0]);
            int to   = Integer.parseInt(ref[1]);

            if(from != to) {
                matrix.computeIfAbsent(to, k -> new ArrayList<>(5));
                matrix.get(to).add(from);
            }
        }
        System.out.println(matrix.toString());

        // [3] 인접 행렬 최대값 찾기
        int max = 0;
        Set<Integer> keySet = matrix.keySet();
        for(Integer key : keySet) {
            int s = matrix.get(key).size();
            if (s > max) max = s;
            System.out.println(max);
        }

        // [4] 최댓값과 일치하는 애들 찾기
        for(Integer key : keySet) {
            int s = matrix.get(key).size();
            if (s == max) result.add(key);
        }
        System.out.println(result.toString());

        Collections.sort(result);
        String output = result.stream().map(String::valueOf).collect(Collectors.joining(" "));
        System.out.println(output);
    }
}