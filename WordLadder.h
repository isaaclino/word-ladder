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
 * Filename :       WordLadder.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <string>

#include <queue>
#include <list>
#include <stack>
#include <vector>

#ifndef WORDLADDER_H
#define WORDLADDER_H


using namespace std;

class WordLadder
{
private:
    
    bool compare( const string &start, const string &end, string &word );
    bool findLadder(const string &start, const string &end);
    void findWords(const string &start, const string &end);

    
protected:
    list<string> Dictionary;
    stack<string> Stack;
    queue<stack<string> > QueueStack;
    vector<string> Vector;

public:
    //Constructor that passes in the name of the dictionary file
    WordLadder(const string &listFile);
    
    //passes in the start and end words and outputs to standard output in ladder
    void outputLadder(const string &start, const string &end);
    
    bool EndFile;
    bool WordNotFound;
    bool Empty; 
    
    
};
#endif
