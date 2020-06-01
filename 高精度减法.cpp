#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool cmp(vector<int> A,vector<int>B)
{
    if(A.size() != B.size()) return A.size()>B.size();
    
    for(int i = A.size()-1;i>=0;--i)
        if(A[i] != B[i])
            return A[i]>B[i];
    return true;
}

vector<int> sub(vector<int>&A,vector<int>&B)
{
    vector<int>C;
    for(int i=0,t=0;i<A.size();++i)
    {
        //123456
        //122228
        t = A[i] - t;
        if(i<B.size()) t = t - B[i];
        C.push_back((t+10)%10); // -2+10 = 8  8%10 = 8
        if(t < 0)  //表示进位
            t = 1;
        else 
            t = 0;
    }
    
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main()
{
    string a,b;
    cin>>a>>b;
    vector<int>A,B;
    for(int i=a.size()-1;i>=0;--i) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;--i) B.push_back(b[i]-'0');
    
    if(cmp(A,B))
    {
        auto C = sub(A,B);
        for(int i=C.size()-1;i>=0;--i)
            cout<<C[i];
    }
    else
    {
        auto C = sub(B,A);
        printf("-");
        for(int i=C.size()-1;i>=0;--i)
            cout<<C[i];
    }
}
