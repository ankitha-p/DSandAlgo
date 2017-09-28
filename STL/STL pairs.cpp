#include<iostream>
//#include<stdlib.h>

using namespace std;

int main(){

    pair<int, string> p=make_pair(122,"ankitha");
    pair<int,string> p1;
    p1.first=121;
    p1.second="Alekya";
    pair<int,string> p2=p;
    cout<<p1.first<<" "<<p1.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
    bool a=(p!=p1),b=(p>=p1),c=(p<=p1);
    cout<< a <<"\t"<< b<<"\t"<<c<<endl;
    return 0;
}
