#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <cassert>
#include <fstream>
#include <cstdlib>

int main(int argc,char* argv[]){
   

    if (argc != 4){
        std::cout<<"Неправильное количество аргуметов"<<"\n";
        return 1;
    }
    std::vector<int> a = {};
    std::vector<int> b = {};
    std::ifstream tape(argv[1]);
    
    long int elem = 0;
    while (tape>>elem){
        a.push_back(elem);
    }
    tape.close();

    std::ifstream out_tape(argv[2]);
    
    long int elem1 = 0;
    while (out_tape>>elem){
        b.push_back(elem);
    }
    out_tape.close();
    int test_num = std::atoi(argv[3]);
    std::sort(a.begin(),a.end());
    std::cout<<"Тест №"<<test_num<<" "<< "выполняется..."<<"\n";
    assert(a==b && "Sorting was incorrect");
    std::cout<<"Тест №"<<test_num<<" "<< "пройден"<<"\n";
    return 0;
}
