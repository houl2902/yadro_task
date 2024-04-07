#include "SortClass.h"
#include <iostream>


SortClass::SortClass(){
}

void SortClass::sortByTwoTapes(Tape* first_tape,Tape* second_tape,Tape* input_tape){
    bool flag_v1 = true;
    bool flag_v2 = false;
    int size_input = input_tape->getSize();
    first_tape->setSize(0);
    second_tape->setSize(0);
    for (int i = 1;i<size_input;i++){
        int value1 = input_tape->readIndex(i-1);
        int value2 = input_tape->readIndex(i);
        input_tape->rewindTape();
        if (value1<value2){
            if (flag_v1 == true){
               first_tape->pushBack(value1);
            }
            else{
               second_tape->pushBack(value1);
            }
        }
        else{
            if (flag_v1 == true){
               first_tape->pushBack(value1);
            }
            else{
               second_tape->pushBack(value1);
            }
            bool temp = flag_v1;
            flag_v1 = flag_v2;
            flag_v2 = temp;
        }
        input_tape->rewindTape();
    }
    int last_value = input_tape->readIndex(size_input-1);
    if (flag_v1 == true){
        first_tape->pushBack(last_value);
        }
    else{
        second_tape->pushBack(last_value);
    }
}

void SortClass::mergeIntoOneTape(Tape* first_tape,Tape* second_tape,Tape* output_tape){
    
    int size_needed = output_tape->getSize();

    output_tape->setSize(0);
    int temp_counter1 = 0;
    int temp_counter2 = 0;
    int size1 = first_tape->getSize();
    int size2 = second_tape->getSize();
    int value1 = 0;
    int value2 = 0;
    while (output_tape->getSize()<size_needed) {
        if (size1-temp_counter1 != 0 && size2-temp_counter2 != 0 ){
            value1 = first_tape->readIndex(temp_counter1);
            first_tape->rewindTape();
            value2 = second_tape->readIndex(temp_counter2);
            second_tape->rewindTape();
            if (value1>value2){
                output_tape->pushBack(value2);
                temp_counter2++;
            }
            else{
                output_tape->pushBack(value1);
                temp_counter1++;
            }
            ;
        }
        else if (size1-temp_counter1 == 0){
            output_tape->rewindTape();
            value2 = second_tape->readIndex(temp_counter2);
            temp_counter2++;
            second_tape->rewindTape();
            output_tape->pushBack(value2);
        }
        else if (size2-temp_counter2 == 0){
            output_tape->rewindTape();
            value1 = first_tape->readIndex(temp_counter1);
            temp_counter1++;
            first_tape->rewindTape();
            output_tape->pushBack(value1);
        }
    }
}

bool SortClass::checkSorted(Tape* input_tape){
    int size_tape = input_tape->getSize();
    bool flag = true;
    int temp_val1 = 0;
    int temp_val2 = 0;
    for (int i = 1;i<size_tape;i++){
        temp_val1 = input_tape->readIndex(i-1);
        temp_val2 = input_tape->readIndex(i);
        if (temp_val1>temp_val2){
            flag = false;
            break;
        }
    }
    return flag;
}


SortClass::~SortClass(){
}