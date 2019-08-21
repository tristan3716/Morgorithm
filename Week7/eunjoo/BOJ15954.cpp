#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    vector<int> kakao;
    vector<double> result;

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; ++i)
    {
        int temp;
        scanf("%d", &temp);

        kakao.push_back(temp);
    }

    for(;K<=N; ++K){
        for(int i=0; i<=N-K; ++i)
        {
            int deviation = 0;
            int temp = i;
            for(int j=0; j<K; ++j)
            {
                deviation += kakao.at(temp);
                temp++;
            }
            double m = (double)deviation/(double)K;

            int temp_2 = i;
            double variance = 0;
            for(int j=0; j<K; ++j)
            {
                variance += abs(kakao.at(temp_2) - m) * abs(kakao.at(temp_2) - m);
                temp_2++;
            }

            result.push_back(sqrt(variance/K));

        }
    }

    double min = *min_element(result.begin(), result.end());

    printf("%.7lf", min);
    return 0;

}