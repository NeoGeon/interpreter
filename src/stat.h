#ifndef __STAT_H_
#define __STAT_H_
#include <string>
using namespace std;
enum Stat{
    Base,
    Initial,
    NotMatch,
    Matched
};

class State{
private:
    string* exp;
    int present;
    int strLen;
    const static Stat stateType = Base; 
public:
    State();
    State(string* exp);
    State(string* exp, int pos);
    virtual State* nextState(char ch)=0;
    virtual Stat type()=0;
    ~State(){};
};


class InitialState:public State{
private:
    string* exp;
    int present;
    int strLen;
    const static Stat stateType = Initial;
public:
    InitialState(string* exp, int pos);
    State* nextState(char ch);
    Stat type(){return InitialState::stateType;};
    ~InitialState();
};

class NotMatchState:public State{
private:
    string* exp;
    int present;
    int strLen;
    const static Stat stateType = NotMatch;
public:
    Stat type(){return NotMatchState::stateType;};
    NotMatchState(string* exp, int pos);
    State* nextState(char ch){return NULL;};
    ~NotMatchState(){};
};

class MatchedState:public State{
private:
    string* exp;
    int present;
    int strLen;
    const static Stat stateType=Matched;
public:
    Stat type(){return MatchedState::stateType;};
    MatchedState(string* exp, int pos);
    State* nextState(char ch){return NULL;};
    ~MatchedState(){};
};

#endif
