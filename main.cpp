/**
 * Course: CS 14 Summer 2016
 *
 * First Name:      Isaac
 * Last Name:       Lino
 * Username:        ilino
 * email address:   ilino001@ucr.edu
 *
 *
 * Assignment:      assn2
 * Filename :       main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <cstdlib>
#include <iostream>
#include "WordLadder.h"

using namespace std;

int main( int argc, char* argv[] ) {
    // we need for arguments <file.out> <dictionary.dictionary> <first_word> <last_word>
    if ( argc != 4 )
    {
        // warning message if no proper arguments were passed. kill and returnt 0
        std::cout<<"\n\n To open a file use: "<< argv[0] <<" <dictionary.ext> <first_word> <last_word>\n\n";
        return 0;
    }
    else
    {
        std::cout << "\n\n***** Word Ladder *****\n\n" << "Start Word:\t" << argv[2] << "\nEnd Word:\t" << argv[3] <<"\n"<<std::endl;
        
        // passes the name of the file
        WordLadder wl( argv[1] );
        
        // passes StartWord as argv[2] and EndWord as argv[3]
        wl.outputLadder( argv[2], argv[3] );
    }
    return 0;
}






