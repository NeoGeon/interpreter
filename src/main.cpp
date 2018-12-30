#include<iostream>
#include<string>
#include"stat.h"
#include"regrexEngine.h"
using namespace std;
int main(int argc, char* argv[]){
    string re;
    string p;
    re = argv[1];
    p = argv[2];
    RegrexEngine reEngine;
    bool result=reEngine.match(re, p);
    cout<<"matched result:"<<re<<" "<<p;
    if(result){
        cout<<" matched"<<endl;
    }else{
        cout<<" not matched"<<endl;
    }
    return 0;
}
