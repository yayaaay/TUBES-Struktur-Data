#include <iostream>
using namespace std;

#define next(p) (p)->next
#define first(l) ((l).first)
#define Top(S) ((S).Top)
#define info(S) ((S).info)
#define infoInt(Cl) ((Cl).info)
#define infoQ(p) (p)->info


struct infotypesQ{
    string nama;
    string eks;
    string pos;
    int cal;
};

typedef struct element *adr;

struct element {
    infotypesQ info;
    adr next;
};

struct Queue {
    adr first;
};


typedef char infotypes;

struct stack {
    infotypes info[50];
    int Top;
};

typedef int infotypess;

struct stackInt {
    infotypess info[50];
    int Top;
};

//queue
void newqueue(Queue &l);
adr createElm(infotypesQ x);
void insertQueue(Queue &l, adr p);
void show(Queue l);
void show2(Queue l);

//stack
void createStack(stack &S);
void createstackInt(stackInt &Cl);
bool isEmpty(stack S);
bool isEmptyInt(stackInt Cl);
bool isFull(stack S);
bool isFullInt(stackInt Cl);
void push(stack &S, char x);
void pushInt(stackInt &Cl, int x);
infotypes pop(stack &S);
infotypess popInt(stackInt &Cl);
void printInfo(stack S);
string toPostfix(adr &p, stack &S);
int isOperator(char c);
int calculate(stackInt &Cl, string postExp);



