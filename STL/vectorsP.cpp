#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<int> v1(5);
    for(int k=0;k<5;k++) v1[k]=k;
    for(int i=0;i<5;i++)
        v1.insert(v1.begin()+i,i+1);
    for(vector<int>::iterator j=v1.begin();j!=v1.end();j++)
        cout<<*j;
    cout<<"\n"<<v1.size()<<endl;
    v1.push_back(8);
    cout<<v1.front()<<"\t"<<v1.back()<<endl;
    //int c=
    //int c=
    v1.pop_back();
    cout<<v1.size()<<"\t"<<v1.at(4);
    v1.erase(v1.begin()+3);
    v1.erase(v1.begin(),v1.begin()+4);
    cout<<endl<<v1.size()<<endl;
    v1.clear();
    cout<<v1.size();
    return 0;
}
