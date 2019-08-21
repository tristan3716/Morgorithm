/**
 * [ 상금 헌터 ]
 *
 * 순위	상금	인원
 * 1등	500만원	1명
 * 2등	300만원	2명
 * 3등	200만원	3명
 * 4등	50만원	4명
 * 5등	30만원	5명
 * 6등	10만원	6명
 *
 * 2018년에 개최될 제2회 코드 페스티벌에서는 상금의 규모가 확대되어,
 * 본선 진출자 64명 중 31명에게 아래와 같은 기준으로 상금을 부여할 예정이다.
 *
 * 순위	상금	인원
 * 1등	512만원	1명
 * 2등	256만원	2명
 * 3등	128만원	4명
 * 4등	64만원	8명
 * 5등	32만원	16명
 *
 * 제이지는 자신이 코드 페스티벌에 출전하여 받을 수 있을 상금이 얼마인지 궁금해졌다.
 * 그는 자신이 두 번의 코드 페스티벌 본선 대회에서 얻을 수 있을 총 상금이 얼마인지 알아보기 위해,
 * 상상력을 발휘하여 아래와 같은 가정을 하였다.
 *
 * 제1회 코드 페스티벌 본선에 진출하여 a등(1 ≤ a ≤ 100)등을 하였다.   단, 진출하지 못했다면 a = 0으로 둔다.
 * 제2회 코드 페스티벌 본선에 진출하여 b등(1 ≤ b ≤ 64) 등을 할 것이다. 단, 진출하지 못했다면 b = 0으로 둔다.
 *
 * 제이지는 이러한 가정에 따라, 자신이 받을 수 있는 총 상금이 얼마인지를 알고 싶어한다.
 *
 * @author Sight
 */
import java.util.Scanner;
public class Baekjoon_15953 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int Line=in.nextInt();

        if(Line>=1&&Line<=1000) {

            int[][] rank=new int[Line][2];
            int[] money =new int[Line];

            for(int i =0; i < Line; i++) {
                for(int j = 0; j < 2; j++) {
                    rank[i][j]=in.nextInt();
                }
            }

            for(int i = 0; i < Line; i++) {
                if(rank[i][0]>0) {

                    if(rank[i][0]==1) {
                        money[i] +=5000000;

                    }else if(rank[i][0]<=3) {
                        money[i] +=3000000;
                    }else if(rank[i][0]<=6) {

                        money[i] +=2000000;
                    }else if(rank[i][0]<=10) {
                        money[i] +=500000;

                    }else if(rank[i][0]<=15) {
                        money[i] +=300000;

                    }else if(rank[i][0]<=21) {
                        money[i] +=100000;
                    }
                }
            }
            for(int i = 0; i < Line; i++) {
                if(rank[i][1]>0) {

                    if(rank[i][1]==1) {
                        money[i] +=5120000;
                    }else if(rank[i][1]<=3) {
                        money[i] +=2560000;

                    }else if(rank[i][1]<=7) {
                        money[i] +=1280000;

                    }else if(rank[i][1]<=15) {
                        money[i] +=640000;

                    }else if(rank[i][1]<=31) {
                        money[i] +=320000;
                    }
                }
            }

            for(int i=0; i<Line; i++) {
                System.out.println(money[i]);
            }
        }

    }
}