#include <iostream>
#include <cstdlib>
#include "BSTree.hpp"

using namespace std;
using namespace BSTree;



void choice(){
    cout<<"1. Вывести дерево на экран"<<endl;
    cout<<"2. Вывести список узлов дерева"<<endl;
    cout<<"3. Добавить узел в дерево"<<endl;
    cout<<"4. Удалить узел из дерева"<<endl;
    cout<<"5. Сохранить дерево в файл"<<endl;
    cout<<"6. Загрузить дерево из файла"<<endl;
    cout<<"7. Проверить наличие узла"<<endl;
    cout<<"8. Завершить работу программы"<<endl<<endl;
};

bool endPr(){
    string ch;
    while (true){
        cout<<"Вы уверены, что хотите выйти из программы ? (да|нет) (yes|no)";
        cin >> ch;
        if ((ch =="yes") || (ch=="да")) {
            return true;
        }
        else {
            if ((ch == "no") || (ch=="нет") )
                return false;
        }
    }
}

int main(int argc, char* argv[]) {
    int ch1=0;
    int *arr = new int [argc-1];
    for (int i=0;i<argc-1;i++){
        arr[i]=atoi(argv[i+1]);
    }
    Tree tr;
    for ( int i=0 ;i<argc-1 ;i++){
        tr.insert(arr[i]) ;
    }
    int ch=0;
    bool is_done=false;
    while (! is_done) {
        choice();
        cin >> ch;
        switch (ch) {
            case 1:
                tr.print();
                break;
            case 2:
                cout << "1. Прямой обход" << endl << endl;
                cout << "2. Поперечный обход" << endl << endl;
                cout << "3. Обратный обход" << endl << endl;
                cin >> ch1;
                switch (ch1) {
                    case 1:
                        tr.direct();
                        cout << endl;
                        break;
                    case 2:
                        tr.simmetric();
                        cout << endl;
                        break;
                    case 3:
                        tr.back();
                        cout << endl;
                        break;
                    default:
                        cout << "Неизвестная команда";
                }
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
            {
                if (endPr()) {
                    is_done = true;
                }
                break;
            }
            default:
                cout << "Неизвестная команда";
        }
    }
    return 0;
}
