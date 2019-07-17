<!-- Morgorithm Study #2 -->
# Morgorithm Study #2  
<!-- 주어진 과제 목록 -->
## *pre-task*  
  + Baekjoon 1325 - Efficient hacking  
  + Baekjoon 6603 - Lotto  
  + Baekjoon 11399 - ATM  
  + Programmers - Best album  
  + Programmers - Joystick  
  + Programmers - Way to school  
  
새로 주어진 6문제, 1주차 3문제를 다시 풀어오기
각자 문제를 푼 방식, 접근 방법 등에 대해 간단하게 설명할 수 있도록 준비
  
## *Schedule*  
<!-- 실제 모임 시간과 모임이 이루어진 장소-->
2019.07.17 (Wed) 16:00 ~ 19:00  
Korea Polytech University E519  
  
## *Studies*  
<!-- 스터디 진행간 토의한 내용, 피드백 결과 등을 기록 -->
  >16시부터 E동 519호에서 자기소개 후, 스터디 진행  
  >스터디 진행방식에 대한 간단한 OT  
  >사전 과제로 주어진 3문제 각자가 풀었던 방법 공유 및 각자 복습  
  >다음 과제 선정 → 스터디 시간 외에 진행되도록 조절 예정  
  
<!-- Input Size, Complexity requirements, Algorithm Category, Descriptions -->
  **Baekjoon 1915 - 가장 큰 정사각형**  
  >Input size : n, m <= 1000  
  >Requirements : Time complexity should be less than O(nm * 100)  
  >Category : DP  
  >  
  >2x2 크기의 정사각형이 1로 구성되어있는지 검사  
  >검사 결과에서 다시 2x2 크기의 정사각형을 검사하면 3x3 크기의 정사각형을 찾을 수 있음  
  >  
  >![The largest square](https://github.com/tristan3716/Algorithm/blob/master/images/week1_BOJ_1915_the_largest_square.png)  
  >DP를 적용하여 현재 위치에서 조사한 정사각형의 넓이를 저장  
    
  **Baekjoon 1596 - 영식 함수**  
  >Input size : 1 <= a <= b <= 1,000,000,000  
  >Requirements : Time complexity should be less than O(b / 10)  
  >Category : Brute-force  
  >  
  >어떤 수 X의 지문을 얻는 데 필요한 시간 : O(logb * logb)  
  >임의의 수 X에 대해 X의 지문을 얻는 데 필요한 시간 : O(b * logb * logb)  
  >따라서, 모든 수를 검사하기 시작하면 1%도 검사하지 못하고 *Time Limit Exceed*  
  >  
  >알고있는 사실에 기반하여 접근할 필요 > **임의의 수 X의 지문은 7이다.**  
  >7에서 시작하여 거꾸로, 가능한 모든 경우를 역추적 (*brute-force*)  
    
  **Codeforces 1181B - Split a Number**  
  >Input size : 2 <= l <= 100,000  
  >Requirements : Time complexity should be less than O(l^2)  
  >Category : Greedy  
  ><!-- Feel free to add comments anywhere -->  
  >>***Comment*** *to OctopusSwellfish from Hyeon-uk*
  >>그런 경우에 쓸 수 있는 BIG_INTEGER 자료형이 있어요.  
  >
  >두 BigInteger를 더하기 위해 필요한 시간 O(L)  
  >입력값을 모든 가능한 두 수로 나누는데 필요한 시간 O(L)  
  >모든 경우에 대해 더하는 경우 반드시 *Time Limit Exceed*  
  >따라서 숫자를 더하지 않고, 모든 경우를 탐색할 필요성
  >
  >![Split a number, testcase "1234567"](https://github.com/tristan3716/Algorithm/blob/master/images/week1_Codeforces_1181B_split_a_number.png)  
  >**두 수의 합은 중간에서 자를 때 가장 작다**  
  >순서대로 모든 가능한 위치에 대해 "두 수의 차이"를 저장하고 이를 비교.  
  >차이가 가장 작은 위치가 합이 가장 작은 경우  


## *Next schedule*  
<!-- 다음 스터디 수행 일정(이슈)을 태그함 -->
[Morgorithm Study Schedule \#3](https://github.com/tristan3716/Morgorithm/issues/1)  
