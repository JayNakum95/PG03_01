#include <iostream>
#include <thread>// include the thread library

void print1() {
	std::cout << "thread 1" << std::endl;// print message from thread 1
}

void print2() {
	std::cout << "thread 2" << std::endl;// print message from thread 2
}

void print3() {
	std::cout << "thread 3" << std::endl;// print message from thread 3
}

int main() {
	std::thread t1(print1);// create thread 1
	t1.join(); // wait for thread 1 to finish

	std::thread t2(print2);// create thread 2   
	t2.join(); // wait for thread 2 to finish

	std::thread t3(print3);// create thread 3
    t3.join();// wait for thread 3 to finish 

    return 0;
}