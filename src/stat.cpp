#include<iostream>
#include<string>
#include"stat.h"
// some problems are that we should do some gc for state change
// this means we need a register for gc
State::State(){;}
State::State(string *exp):exp(exp), present(0){
   strLen=exp->length();
}
State::State(string *exp, int pos):exp(exp),present(pos){;}

InitialState::InitialState(string *exp, int pos):exp(exp), present(pos){
}
InitialState::~InitialState(){;}

State* InitialState::nextState(char ch){
    string& tmpExp = *exp; 
    if(ch==tmpExp[present]){
        if(present+1==strLen){
            return new MatchedState(exp, present);
        }else{
            present+=1;
            return this;
        }
    }else{
        return new NotMatchState(exp, present);
    }
}

NotMatchState::NotMatchState(string* exp, int pos):State(exp, pos){
    //type=NotMatch;
}

MatchedState::MatchedState(string* exp, int pos):State(exp, pos){
    //type=Matched;
}
