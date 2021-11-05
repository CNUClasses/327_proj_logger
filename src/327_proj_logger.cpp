//============================================================================
// Name        : 327_proj_logger.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "../../object_fileio_lib/src/Logger.h"
using namespace std;
KP::Logger lg;

int main(int argc, char *argv[]) {
	//if logging turned on then there will be a second argument
	//an integer that indicates what to log 
	if(argc ==2){
		int logval = stoi(argv[1]);	//throws exception if the string is NOT numeric 
		
		switch(logval){
		case 0:
			lg.setDest(KP::DEST::None);
			break;
		case 1:
			lg.setDest(KP::DEST::StdOut);
			break;
		case 2:
			lg.setDest(KP::DEST::Fle);
			break;
		case 3:
			lg.setDest(KP::DEST::Fle | KP::DEST::StdOut);
			break;	
		}	
	}
	
	lg.log("in both file and stdout");
	lg.setDest(KP::DEST::Fle);
	lg.log("just in the file");
	lg.setDest(KP::DEST::StdOut);
	lg.log("just stdout");
	lg.setDest(KP::DEST::None);
	lg.log("This will not appear");
	lg.setDest(KP::DEST::StdOut | KP::DEST::Fle);
	lg.log("also in both file and stdout");
	
	return 0;
}
