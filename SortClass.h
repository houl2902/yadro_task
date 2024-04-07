#include "Tape.h"

class SortClass
{
private:
    bool flag_v2;
    bool flag_v1;
public:
   SortClass();
   ~SortClass();
   void sortByTwoTapes(Tape* first_tape,Tape* second_tape,Tape* input_tape);
   void mergeIntoOneTape(Tape* first_tape,Tape* second_tape,Tape* output_tape);
   bool checkSorted(Tape* input_tape);
};