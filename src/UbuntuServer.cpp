//============================================================================
// Name        : UbuntuServer.cpp
// Author      : NESC528
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include "udp.h"

using namespace std;
int main()
{

	UDP * ServerUDP = new UDP(5001);
	ServerUDP->udp_init();
	ServerUDP->udp_start();
	delete ServerUDP;

	return 0;
}
