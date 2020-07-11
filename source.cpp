#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
ifstream dat;
string filename = "shortdata.txt";
string title = "********____CassieCom____********\n\n";

void open(ifstream &file,string path){
    file.open(path);
    if(!file.is_open()) cout << "loading database error\n";
}

void close(ifstream &file){
    
    file.close();;
}

void card (){
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    for (int i = 0; i<9; i++){
        cout<< 'x';
    }
    cout << "\n";
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    cout << "X";
    
    for (int i = 0; i<7; i++){
        cout << " ";
    }
    cout <<"x\n";
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    cout <<"x   C   x";
    cout <<"\n";
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    cout <<"x  C C  x";
    cout <<"\n";
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    cout <<"x C   C x";
    cout <<"\n";
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    cout <<"x  C C  x";
    cout <<"\n";
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    cout <<"x   C   x";
    cout << "\n";
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    cout <<"x";
    for (int i = 0; i<7; i++){
        cout << " ";
    }
    cout << "x";
    cout <<"\n";
    for (int i = 0; i<9; i++){
        cout << " ";
    }
    for (int i = 0; i<9; i++){
        cout<< 'x';
    }


}

string help(){
    ifstream help;
    open(help,"HELP.txt");
    string buffer;
    string out = title;
    while(getline(help,buffer)){
        out = out + buffer+'\n';
    }
 
    return out;
}

string select (string key){
    bool love = false;
    bool normal = false;
    bool kurz = false;
    if (key == "l" || key == "L"|| key == "Love"|| key == "love"){
        love = true;
        filename = "datalove.txt";
    }
    else if (key == "n" || key == "N"|| key == "Normal" || key == "normal"){
        normal = true;
        filename = "data.txt";
    }
    else if (key == "s" || key == "S"|| key == "Short" || key == "short"){
        kurz = true;
        filename = "shortdata.txt";
    }
    
    string res = "Fail to select";
    if ((love && filename == "datalove.txt")||(normal && filename == "data.txt")||(kurz && filename == "shortdata.txt")){
     res = "Selection successful";
    }
    return res;
}

string details(string key){
    system ("cls");
    cout << title;
    open(dat,filename);
    string buffer;
    string res ="";
    
    
    while(getline(dat, buffer)){
        if (buffer == key){
            while (getline(dat,buffer)){
                if (buffer != "000")
                res = res + buffer+'\n';
                if (buffer == "000") break;
            }
            break;
        }
        else if(buffer == "end"){
            res = "Command Not Found\n";
        }
    }
   
    close(dat);
    return res;
}

string handler(string key){
string res;
    if (key == "help" || key == "h" || key == "H") {
        system ("cls");
        res = help();
         return res;
        }
    else if(key == "exit" || key == "e" || key == "E"){
        system ("cls");
        exit(0);
        }
    else if (key == "select"|| key == "s" || key == "S"){
        string key;
        system ("cls");
        cout << title <<"Select format : \n normal/n for Normal spread \n love/l for Love spread\n short/s for short description\n\n>>";
        cin >> key;
        return select(key);
    }
    else return details(key);

}
int main (){
    system ("cls");
    cout << title;
    cout << "     Welcome to CassieCom !!!\n\n";
    card();
    cout << "\n\n NOTE : Details for Normal & Love Spreads are not yet available\n but you can still explore the related commands. ";
    while (true){
    string key;
    cout << "\n\nType Command (help/select/exit/card name):\n>> ";
    cin >> key;
    cout << key;
    cin.ignore();
    cout << handler(key)<<'\n';
    
    }
}
 //To compile : g++ source.cpp -static-libgcc -static-libstdc++ -o cassiecom.exe