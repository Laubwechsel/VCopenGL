#include <iostream>
#include <csignal>
#include "Window.h"
#include <GLFW/glfw3.h>

void signal_handler(int signal_num)
{
	std::cout << "The interrupt signal is (" << signal_num
		<< "). \n";

	// It terminates the  program
	exit(signal_num);
}

int main(void){
	//signal(SIGINT, signal_handler);
	try
	{
		Window mg;
		mg.run();
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << "\nDruecke eine Taste zum beenden." << std::endl;
		std::getchar();
	}


	return 1;
}