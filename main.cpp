#include "SortClass.h"
#include <iostream>

int main(int argc,char* argv[]){
    if (argc != 3){
        std::cout<<"Неправильное количество аргуметов"<<"\n";
        return 1;
    }

    std::string inp = argv[1];
    std::string out = argv[2];
    std::string temp1_file = "tmp/first.txt";
    std::string temp2_file = "tmp/second.txt";
    std::string config_file = "config.txt";
    
    Tape* input = new Tape();
    Tape* output = new Tape();
    Tape* temp1 = new Tape();
    Tape* temp2 = new Tape();
    SortClass* sorter = new SortClass();
    input->setConfig(config_file);
    output->setConfig(config_file);
    temp1->setConfig(config_file);
    temp2->setConfig(config_file);
    input->readTapeFile(inp);
    input->writeTapeFile(out);
    output->readTapeFile(out);
    temp1->createTapeFile(temp1_file);
    temp2->createTapeFile(temp2_file);
    
    do{
        sorter->sortByTwoTapes(temp1,temp2,output);
        sorter->mergeIntoOneTape(temp1,temp2,output);

    } while (sorter->checkSorted(output) != true);
    int delay_input = input->getDelays();
    int delay_output = output->getDelays();
    int delay_temp1 = output->getDelays();
    int delay_temp2 = output->getDelays();
    int sum_delay = delay_input+delay_output+delay_temp1+delay_temp2;
    std::cout<<"Время выполнения сортировки "<<sum_delay<<"\n";
    delete input;
    delete output;
    delete temp1;
    delete temp2;
    delete sorter;
}
