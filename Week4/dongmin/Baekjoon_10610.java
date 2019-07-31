/**
 *
 * 어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다.
 * 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
 *
 * 미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.
 *
 * [입력]
 * N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.
 *
 * [출력]
 * 미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.
 *
 * [예제 입력]      [예제 출력]
 *     30               30
 *     102             210
 *     2931             -1
 *
 * [풀이]
 * 1. 30의 배수는 각 자리 숫자의 합이 언제나 3의 배수가 되어야함
 * 2. 그리고 1의 자리 수가 반드시 0이여야함
 * @author Sight
 * @since  2019. 07 .14
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.Stream;

class Baekjoon_10610 {

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        // [1] 자리수 별로 정수 배열화
        int[] numbers = Stream.of(input.split(""))
                              .mapToInt(Integer::parseInt)
                              .toArray();

        // [2] numbers 배열 값의 합 구하기
        int sum = Arrays.stream(numbers)
                .reduce(Integer::sum)
                .getAsInt();

        // [3] numbers 배열에 0이 하나라도 있는지 확인
        boolean hasZero = Arrays.stream(numbers)
                                .anyMatch(num -> num == 0);

        // [4] numbers 배열의 합이 3의 배수인지 확인
        boolean isDivisorOf3 = (sum % 3 == 0);

        if( hasZero && isDivisorOf3 ){
            mergeSort(numbers, 0 , numbers.length - 1);
            System.gc();
            String result = Arrays.stream(numbers)
                                  .mapToObj(String::valueOf)
                                  .collect(Collectors.joining("")); // {1, 2, 3, 4, 5} to "123456"
            System.out.println(result);
        } else {
            System.out.println(-1); return;
        }
    }// main() end

    /**
     * 머지소트
     *
     * 자바는 primitive int type에 대한 descending 정렬이 없음 직접 구현
     */
    private static void mergeSort(int[] originArr, int start, int end) {
        int middle;
        if(start < end) {
            middle = (start+end)/2;
            mergeSort(originArr, start, middle);        // 좌측 분할
            mergeSort(originArr, middle+1, end);   // 우측 분할
            merge(originArr, start, middle, end);       // 병합
        }
    }// mergeSort() end

    private static void merge(int[] arr, int s, int m, int e){

        // [1] 임시 배열 size 계산
        int l_size = m-s+1;  // 좌측 배열 사이즈
        int r_size = e-m;    // 우측 배열 사이즈

        // [2] 임시 배열 생성 및 값복사
        int[] L = new int[l_size];          // --> disallocation 안되서 메모리 먹음..
        int[] R = new int[r_size];          // --> disallocation 안되서 메모리 먹음..

        for(int i = 0; i < l_size; i++) L[i] = arr[s+i];
        for(int i = 0; i < r_size; i++) R[i] = arr[m+1+i];

        // [3] 병합
        int i = 0, j = 0 ;      // 좌측, 우측 임시배열 idx
        int k = s;              // 원본 배열 idx

        while( i < l_size && j < r_size )
        {
            if(L[i] >= R[j])        // [ASC] L[i] <= R[j]      [DESC] L[i] >= R[j]
            {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // [4] 배열에서 원소들 (홀수일 때) 뒤에 복사 | 양쪽다 홀수 일수는 없음
        while(i < l_size) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < r_size){
            arr[k] = R[j];
            j++;
            k++;
        }

        L = null;
        R = null;
    }// merge() end
}// class end