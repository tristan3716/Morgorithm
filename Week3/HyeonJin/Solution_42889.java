package 실패율_42889;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Solution_42889 {

	public static int[] solution(int N, int[] stages) {
		int []answer = new int[N];	
		Map<Integer,Double> map = new HashMap<Integer,Double>();//key와 value를 사용하기 위한 hashmap
		int stage_length = 0;//변하지 않는 stage 길이
		int stage_length1 = 0; // 변하는 stage길이
		
		//제출용이 아닌 문제풀이용으로 필요한 코드
		/*
		 * for(int i=0;i<stages.length;i++) { if(stages[i]!=0) {
		 * 
		 * stage_length++; } else break; }
		 */
		stage_length = stages.length;//고정 stage 길이 복사	
		int count = 0;
		stage_length1 = stage_length;//최초에 가변 stage길이 복사
		for(int i=1;i<=N;i++)
		{
			
			 if(stage_length1 <=0) //각 단계에 한개도 존재하지 않을경우 
				 stage_length1 = 1; //stage_length1 을 1로 만들어 줘야 나누기 연산에서 오류 안남
			 
			count = 0;
			for(int j=0;j<stage_length;j++)
			{
				if(i==stages[j])//전채 탐색
					count++;
			}
			if(count==0)//없을경우 i번쪠 단계에 0 값 삽입
				map.put(i, 0.0);
			else//1개이상 존재할 경우 연산해서 haspmap에 삽입
			map.put(i, (double)count/stage_length1);
		
			stage_length1-=count;//전체 stage길이 count수 만큼 감소
		}

		
		int count_temp = 0;
		Iterator<Integer> it = sortByValue(map).iterator(); //value 순으로 정렬
		while(it.hasNext()){//answer에 복사
			int temp = (Integer) it.next();
				answer[count_temp] = temp;
				count_temp++;
			  }	 
		return answer;
	}
    public static List<Integer> sortByValue(final Map<Integer, Double> map){
        List<Integer> list = new ArrayList<Integer>();//키 값 정렬을 위한 list 선언
        list.addAll(map.keySet());//list에 keyset 삽입

        Collections.sort(list,new Comparator<Object>(){//정렬
        	@SuppressWarnings("unchecked")
			public int compare(Object o1, Object o2) {
        	Object val1 = map.get(o1);
        	Object val2 = map.get(o2);
	
        	if(val1.equals(val2))	//value값이 동일할 경우 키값 오름차순으로 정렬
        		return Integer.parseInt(o1.toString()) < Integer.parseInt(o2.toString()) ? 1: -1;
        	else//다를경우 value 오름차순
        		return ((Comparable<Object>)val1).compareTo(val2);
        	}
        	});
        Collections.reverse(list); //내림차순으로 정렬
        return list;
    }


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		int N = scanner.nextInt();
		int stages[] = new int[2000001];
		for(int i=0;i<stages.length;i++)
		{
			stages[i] = 0;
		}
		int answer[] = new int[N+1];
		for(int i=0;i<=4;i++)
		{
			
			stages[i] = scanner.nextInt();
		}
		
		answer = solution(N,stages);
		
		  for(int i = 0;i<N;i++) { 
			  
			  System.out.print(answer[i]); 
			if(i!=N-1)
				System.out.print(", ");
		  }
		 
		System.out.println();
		
		scanner.close();
	}

}
