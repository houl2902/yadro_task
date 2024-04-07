#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "Tape.h"

Tape::Tape(){
    int _size = 0;
	int _tape_position = 0;
    int _delay_for_incr = 0;
    int _delay_for_rewind = 0;
    int _delay_for_read_write = 0;
    std::vector<int> tape_array = {};
    int sum_delay = 0;
    std::string _file_path = "";
}

Tape::~Tape(){
}

int Tape::getTapePosition(){
    return _tape_position;
}

int Tape::getSize(){
    return _size;
}

void Tape::setSize(int size){
    if (size==0){
        tape_array.clear();
    }
    _size = size;

}

int Tape::readIndex(int index){
    
    if (_tape_position!=index){
        sum_delay+= _delay_for_incr*std::abs(index-_tape_position);
    }
    setTapePosition(index);
    sum_delay+=_delay_for_read_write;
    
    return tape_array[index];
}

int Tape::setTapePosition(int index) {
    index = cheakBound(index);
    _tape_position = index;
    return _tape_position;
}

int Tape::getDelays() {
    return  sum_delay;
}

void Tape::writeTapeFile(std::string path_to_file){
    std::ofstream output(path_to_file);
    if (_tape_position!=0){
        sum_delay+=_tape_position*_delay_for_incr;
    }
    for (int i = 0;i<_size;i++){
        if (i == _size-1){
            output<<tape_array[i];
        }
        else{
            output<<tape_array[i]<<" ";
        }
        
        sum_delay+=_delay_for_incr;
    }
    setTapePosition(_size-1);
    output.close();
}

int Tape::cheakBound(int position){
    if (position<0){
       _tape_position = 0 ;
    }
    return position;
}
void Tape::pushBack(int value){
    if (_size != 0){
        sum_delay+= _delay_for_incr*std::abs(_size-_tape_position);
    }
    sum_delay+=_delay_for_read_write;
    tape_array.push_back(value);
    _size++;
    writeWithoutDelays();
}
void Tape::writeWithoutDelays() {
    std::fstream output(_file_path, std::ios::out | std::ios::trunc);
    output.close();

    std::ofstream out(_file_path);
 
    for (int i = 0; i< _size; i++){
        if (i == _size-1){
            out<<tape_array[i];
        }
        else{
            out<<tape_array[i]<<" ";
        }
    }
    out.close();
}

void Tape::rewindTape() {
    sum_delay+=_delay_for_rewind;
}

void Tape::setConfig(std::string path_to_config) {
    try
    {
      std::ifstream config(path_to_config);
      std::string data;
      for (int i = 0; i<3;i++){
        std::getline(config,data);
        auto num = data.substr(data.find(":")+1,10);
        int delay = std::atoi(num.c_str());
        
        if (i == 0){
            _delay_for_incr = delay;
        }
        else if(i==1){
            _delay_for_rewind = delay;
        }
        else if(i==2){
            _delay_for_read_write = delay;
        }
      }
      config.close();

    }
    catch(...)
    {
        std::cout<<"INVALID PATH"<<"\n";
    }
}

void Tape::createTapeFile(std::string path_to_file) {
    std::ofstream new_file(path_to_file);
    _file_path = path_to_file;
    new_file.close();
}

void Tape::readTapeFile(std::string path_to_tape_file) {
    try
    {
      std::ifstream tape(path_to_tape_file);
    
      long int elem = 0;
      int index = 0;
      while (tape>>elem){
        tape_array.push_back(elem);
        _size+=1;
      }
      tape.close();
      _file_path = path_to_tape_file;
    }
    catch(...)
    {
        std::cout<<"INVALID PATH"<<"\n";
    }
}
