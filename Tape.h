
#include <fstream>
#include <string>
#include <vector>

class Tape
{
private:
    int _size;
    int _tape_position;
    int _delay_for_incr;
    int _delay_for_rewind;
    int _delay_for_read_write;
    int sum_delay;
    std::string _file_path;
    std::vector<int> tape_array;

public:
	Tape();
	~Tape();

	int getTapePosition();
	int getSize();
	int readIndex(int index);
    int setTapePosition(int index);
    int getDelays();
    void writeTapeFile(std::string path_to_file);
    void writeWithoutDelays();
    void rewindTape();
    void setConfig(std::string path_to_config);
    void createTapeFile(std::string path_to_file);
    void readTapeFile(std::string path_to_tape_file);
    void setSize(int size);
    int cheakBound(int index);
    void pushBack(int value);
};
