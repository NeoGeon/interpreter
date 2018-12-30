#include<iostream>
#include<string>
#include "stat.h"
#include "regrexEngine.h"
using namespace std;
RegrexEngine::RegrexEngine(){};

bool RegrexEngine::match(string regrex, string str){
     string* pRegrex = &regrex;
     State* state = new InitialState(pRegrex, 0);
     int len=str.length();
     for(int i=0;i!=len;i++){
	State* nextState;
        nextState = state->nextState(str[i]);
        state = nextState;
        if(nextState->type()==NotMatch){
            return false;
        }
     }
     return true;
}
