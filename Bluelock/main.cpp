#include "bluelock.h"

int main()
{
    cout << "========== WELCOME =========="<<endl;
    cout << endl;

    stack S;
    stackInt Cl;
    Queue l, l2;
    adr p;
    infotypesQ x;


    string name;
    string eks;

    createStack(S);
    createstackInt(Cl);
    newqueue(l);
    newqueue(l2);
    int i;

    cout << "Masukan Jumlah Data : ";
    cin  >> i;
    cout << endl;

    int i2 = 1;
    while( i2 <= i){
        cout << "Insert Your name : ";cin >> name;
        cout << "insert Your infix : ";cin >> eks;
        cout << endl;
        x.nama = name;
        x.eks = eks;
        x.cal = NULL;
        p = createElm(x);
        insertQueue(l, p);
        i2++;
    }


    cout<<endl;
    cout << "========== SHOW DATA ========="<<endl;
    cout << endl;
    show(l);
    cout << endl;

    cout << "====== INFIX TO POSTFIX ======"<<endl;
    cout << endl;


    adr p1 = first(l);
    while(p1 != NULL){
        string pos = toPostfix(p1, S);
        infotypesQ x2;
        x2.nama = infoQ(p1).nama;
        x2.eks = infoQ(p1).eks;
        x2.pos = pos;
        adr p2 = createElm(x2);
        insertQueue(l2, p2);

        int rsl = calculate(Cl, pos);
        infoQ(p1).cal = rsl;

        p1 = next(p1);
    }
    show2(l2);

    cout << "========== RESULT ==========="<<endl;
    cout << endl;

    show(l);


    return 0;
}
