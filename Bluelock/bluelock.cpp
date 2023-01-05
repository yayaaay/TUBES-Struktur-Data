#include "bluelock.h"
#include<math.h>

void newqueue(Queue &l){
    first(l) = NULL;
}

adr createElm(infotypesQ x){
    adr p = new element;

    infoQ(p) = x;
    next(p) = NULL;
    return p;
}

void insertQueue(Queue &l, adr p){
    if (first(l) == NULL){
        first(l) = p;
    } else{
        adr q = first(l);
        while(next(q) != NULL){
            q = next(q);
        }
        next(q) = p;
    }
}


void show(Queue l){
    adr q = first(l);
    int i = 1;
    while(q != NULL){
        if(infoQ(q).cal == NULL){
            cout << "(" << i << ")" << endl;
            cout << "Name    : " << infoQ(q).nama << endl;
            cout << "Infix   : " << infoQ(q).eks;
            cout <<endl;
            cout << endl;
        } else if(infoQ(q).cal != NULL){
            cout << "(" << i << ")" << endl;
            cout << "Name   : " << infoQ(q).nama << endl;
            cout << "Infix  : " << infoQ(q).eks << endl;
            cout << "Result : " << infoQ(q).cal;
            cout <<endl;
            cout <<endl;
        }
        q = next(q);
        i++;

    }
}

void show2(Queue l){
    adr q = first(l);
    int i = 1;
    while(q != NULL){
        cout << "(" << i << ")" << endl;
        cout << "Name    : " << infoQ(q).nama << endl;
        cout << "Infix   : " << infoQ(q).eks << endl;
        cout << "Postfix : " << infoQ(q).pos;
        cout <<endl;
        cout <<endl;
        q = next(q);
        i++;
    }
}


void createStack(stack &S) {
    Top(S) = -1;
}

void createstackInt(stackInt &Cl) {
    Top(Cl) = -1;
}

bool isEmpty(stack S) {
    if (Top(S) == -1) {
        return true;
    }

    return false;
}

bool isEmptyInt(stackInt Cl) {
    if (Top(Cl) == -1) {
        return true;
    }

    return false;
}

bool isFull(stack S) {
    if (Top(S) == 50) {
        return true;
    }

    return false;
}

bool isFullInt(stackInt Cl) {
    if (Top(Cl) == 50) {
        return true;
    }

    return false;
}

void push(stack &S, char x) {
    infotypes u;
    u = x;
    if (!isFull(S)) {
        Top(S)++;
        info(S)[Top(S)] = u;
    } else {
        cout << "List Penuh" << endl;
    }
}

void pushInt(stackInt &Cl, int x) {
    infotypess u;
    u = x;
    if (!isFullInt(Cl)) {
        Top(Cl)++;
        infoInt(Cl)[Top(Cl)] = u;
    } else {
        cout << "List Penuh" << endl;
    }
}

infotypes pop(stack &S) {
    infotypes x;

    if (!isEmpty(S)) {
        x = info(S)[Top(S)];
        Top(S)--;
        return x;
    } else {
        cout << "List Kosong" << endl;
    }
}

infotypess popInt(stackInt &Cl) {
    infotypess x;

    if (!isEmptyInt(Cl)) {
        x = infoInt(Cl)[Top(Cl)];
        Top(Cl)--;
        return x;
    } else {
        cout << "List Kosong" << endl;
    }
}

void printInfo(stack S) {
    int q = 1;
    if (!isEmpty(S)) {
         for (int i = Top(S); i > -1; i--) {
                cout << "(" << q <<")"<<endl;
                cout << "Name : " << info(S)[i];
                cout << endl;
                q++;
        }
    } else {
        cout << "List kosong" << endl;
    }
    cout << endl;
}

int isOperator(char c){
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string toPostfix(adr &p, stack &S){
    string result;

    for (int i = 0; i < infoQ(p).eks.length(); i++) {
        char c = infoQ(p).eks[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                result += c;
            } else if(c == '('){
                push(S, c);
            } else if(c == ')'){
                int v = Top(S);
                while(info(S)[v] != '('){
                        result += info(S)[v];
                        pop(S);
                        v--;
                        }
                pop(S);
            } else{
                int k = Top(S);
                while(!isEmpty(S) && isOperator(c) <= isOperator(info(S)[k])){
                        result += info(S)[k];
                        pop(S);
                        k--;
                }
                push(S,c);
            }

    }
    int g = Top(S);
    while(!isEmpty(S)){
        result += info(S)[g];
        pop(S);
        g--;
    }

    return result;

}


int calculate(stackInt &Cl, string postExp){
    int ln = postExp.length();

    for(int pj = 0; pj < ln; pj++){
        char ch = postExp[pj];

        if(ch >= '0' && ch <= '9'){
            pushInt(Cl, ch - '0');
        } else{
            int a1 = Top(Cl);
            int a = infoInt(Cl)[a1];
            popInt(Cl);

            int b1 = Top(Cl);
            int b = infoInt(Cl)[b1];
            popInt(Cl);

            switch(ch){
                case '+':
                    pushInt(Cl, b + a);
                    break;
                case '-':
                    pushInt(Cl, b - a);
                    break;
                case '*':
                    pushInt(Cl, b * a);
                    break;
                case '/':
                    pushInt(Cl, b / a);
                    break;
                case '^':
                    pushInt(Cl,pow(b,a));
                    break;
            }
        }
    }
    int rslt = Top(Cl);
    return infoInt(Cl)[rslt];
}
