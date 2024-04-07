all: tests
	echo "ALL STARTED"

command:
	g++ main.cpp Tape.cpp SortClass.cpp -o main
tests: command
	g++ test.cpp -o test
	./main tests/input1.txt tests/output1.txt
	./test tests/input1.txt tests/output1.txt 1
	./main tests/input2.txt tests/output2.txt
	./test tests/input2.txt tests/output2.txt 2
	./main tests/input3.txt tests/output3.txt
	./test tests/input3.txt tests/output3.txt 3
clear:
	rm -f main.o
