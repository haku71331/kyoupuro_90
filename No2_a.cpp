//問題https://x.com/e869120/status/1377027868518064129

#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int n,a,cnt;
    string str = "";

    cin >> n;
    
    for (int i = 0; i < pow(2,n); i++)
    {
        str = "";
        a = i;
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if(a % 2 == 1){
                str = str + "(";
                cnt++;
            }else{
                str = str + ")";
                cnt--;
            }
            a = a/2;
            if(cnt < 0) break;
        }
        if(cnt == 0){
            cout << str << endl;
        }   
    }
    

    return 0;

}