#include <iostream>
#include <vector>
#include <string>

using namespace std;

string onoff;
int result;
int N;

int asdf(vector< vector<int> >plant, int index, int number)
{
    if(index==number)
        return 0;
    else if(onoff.at(index)=='Y')
        return 0;
    else
    {
        
    }

    return 1;
}

int main()
{
    int temp;
    cin >> N;

    vector< vector<int> > plant(N, vector<int>(N));

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            cin >> temp;
            plant[i][j] = temp;
        }
    }

    cin >> onoff;

    result = asdf(plant, 0, N);
    cout << result;

    return 0;
}