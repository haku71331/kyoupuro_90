//No1

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
typedef long long llint;

int main(void){
    llint l,k,n,a,ans,parts;
    llint before_parts = 0;
    llint j = 0;
    vector<llint> A,cut;

    cin >> n >> l;//切れ目の数、ようかんの長さ
    cin >> k;//切れる数

    for (llint i = 0; i < n; i++)
    {
        cin>> a;
        A.push_back(a);
    }

    ans = l;//切れ目0ならこれが答え

    for (llint i = k; i > 0; i--)
    {
        parts = ((l-before_parts)/(i+1)) + before_parts;
        cout << "parts = " << parts << endl;
        while (true)
        {
            if (abs(parts - A[j]) < abs(parts - A[j+1]))
            {
                break;
            }else if(j + 1 > n){
                cout << "[j+1] overflow!" << endl;
                break;
            }

            j++;
            
        }//A[j]がpartsから一番近い値

        cout << "A[" << j << "] = " << A[j] << endl; 

        if(ans > A[j] - before_parts)
        {
            ans = A[j] - before_parts;
        }

        before_parts = A[j];
        
    }

    if((l - before_parts) < ans){
        ans = l -before_parts;
    }
    
    cout << ans << endl;

}
