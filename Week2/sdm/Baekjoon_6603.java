/**
 *
 * 독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.
 * 로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라
 * 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.
 *
 * 예를 들어,
 * k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는
 * 경우의 수는 총 28가지이다.
 * ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
 *
 * 집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
 *
 * @author Sight
 * @since  2019. 07 .14
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br             = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder  buffer         = new StringBuilder(80);
        List<String>   inputContainer = new ArrayList<>(30);

        // [1] input 값 세팅
        while(true) {
            String input = br.readLine().trim();

            if("0".equals(input)) break;
            else inputContainer.add(input);
        }
        br.close();

        // [2] 입력 값 라인별로 처리
        for(int i = 0 ; i < inputContainer.size() ; i++) {
            String input = inputContainer.get(i);

            // [a] 입력 받은 line int 배열로 변환
            int[] arr = Stream.of(input.split(" "))
                              .mapToInt(Integer::parseInt)
                              .toArray();

            // [b] 입력받은 배열에서 사이즈와 표본 분리
            int t_size = arr[0];                                // data [1] : 사이즈
            int[] t = Arrays.copyOfRange(arr, 1, arr.length);   // data [2] : 번호 조합 array

            // [c] 조합 생성
            int[] result = new int[6];
            combination(t, result, t_size, 6, 0, 1, buffer);

            if(i != inputContainer.size()-1) { System.out.println("");}
        }
    }

    /**
     * n개의 표본중 R개의 조합을 뽑는 공식
     *
     * nCr = (n-1)C(r-1) + (n-1)Cr
     *
     * @param origin  원본 배열
     * @param result  결과 저장할 배열
     * @param n       표본 개수
     * @param r       추출 할 개수
     * @param idx     현재 결과 배열의 위치 인덱스
     * @param target  원본 배열의 현재 위치 인덱스
     * @param buffer  출력용 버퍼
     */
    public static void combination(int[] origin, int[] result, int n, int r, int idx, int target, StringBuilder buffer) {
        if(r == 0){ print(result, idx, buffer); }
        else if(target-1 == n) return;
        else {
            result[idx] = origin[target-1];
            combination(origin, result, n, r-1, idx+1, target+1, buffer);
            combination(origin, result, n, r, idx, target+1, buffer);
        }
    }

    /**
     * 출력용 함수
     * 
     */
    public static void print(int[] arr, int length, StringBuilder buffer) {
        for (int i = 0; i < length; i++) buffer.append(arr[i]).append(" ");
        String result = buffer.toString().trim();
        System.out.println(result);
        buffer.setLength(0); // buffer clear
    } //end combination()
}