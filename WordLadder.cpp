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
 * Filename :       WordLadder.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>


#include <stack>
#include <queue>
#include <list>
#include <vector>

#include <string>

#include "WordLadder.h"

using namespace std;

/*----------------------------------------------------------------------------------*/
WordLadder::WordLadder(const string &listFile)
{
    // open file from file from listFile file passed from main with arguments
    ifstream file(listFile.c_str());
   
    if(!file)
    {
        //check if there is a file or it is open, if not return. kill
        cout << "Dictionary file does not exist\n\n";
        return;
    }
    
    else
    {
        while(file)
        {
            // stores the words in string words
            string words;
            file >> words;
            
            // if it reaches the end, push all the words
            if(words!="\0")
            {
                Dictionary.push_back(words);
            }
         
        }
    }
    // close the file after reading all the words
    file.close();
}
/*----------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------*/
void WordLadder::outputLadder(const string &start, const string &end )
{
    if(findLadder(start, end))
    {
        cout << "\nWord ladder found!\nfrom " << start << " to " << end << "\n\n";
        
        while(!QueueStack.back().empty())
        {
            cout << QueueStack.back().top() << endl;
            QueueStack.back().pop();
        }
        
    }
    
    else
    {
        cout << "Words NOT found\nStart: '" << start << " End: " << end << "'!\n\n";
        return;
        
    }
    cout << endl;
}
/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
bool WordLadder::compare( const string &start, const string &end, string &word )
{
    // if words are not the same size, kill it
    if( start.length( ) != end.length( ) )
    {
        cout << "Words are not same size"<<endl;
        cout<< "Start word has " << start.size() << " characters and End word has " << end.size()<<" characters\n" <<endl;
        exit(-1);
    }
    
    else if(start.size()!=5 && end.size()!=5)
    {
        cout << "Mismatch word size!\nlimit your words to 5 characters\n\n"<<endl;
        exit(-1);
    }
    
    else
    {
        for(unsigned int i=0; i< Vector.size(); i++)
        {
            cout << word <<"\t";
            if(Vector.at(i)==word)
            {
                return true;
            }
        }
    }
    
    return false;
}

/*----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
void WordLadder::findWords(const string &start, const string &end)
{
    list<string>::iterator iterator = Dictionary.begin();
    
    
   
    EndFile = false;
    string word;
    
    
    Stack.push(start);
    
   int counter=0;
   while(counter!= int (Dictionary.size()) && !EndFile)
   {
    
       // pass the the begining of the dictionary to word
        word = *iterator;
       
        int count=0;
        for(unsigned int index=0; index< word.size(); index++)
        {
            if(word.at(index)!=start.at(index))
            {
                count++;
            }
        }
       
        // compare word by word until the end is reached
        if(count==1 && !compare(start, end, word))
        {
             iterator++;                //increment iterator as found
            
             Vector.push_back(word);    //push word at the end on vector
            
             Stack.push(word);          //push at top word for list and queue stack
             QueueStack.push(Stack);
             Stack.pop();
            
             Dictionary.remove(word);   //eliminate word as found
            
            if(word==end)
            {
                EndFile = true;
            }
        }
        else
        {
            iterator++;
        }
        counter++;
     }
}
/*----------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------*/
bool WordLadder::findLadder(const string &start, const string &end)
{
  
    EndFile = false;
    WordNotFound = false;
    Empty = false;
    vector<string> VectorWords;
    long QueueStackSize;
  
    Dictionary.remove(start);
    
    findWords(start, end);
    if(start == end)
    {
        
        Stack.push(start);
        Stack.push(end);
        QueueStack.push(Stack);
        
        //return true;
    }
    

    long VectorSize = Vector.size();
    for (int i=0; i<VectorSize; i++ )
    {
        if(Vector.at(i)==end)
        {
            EndFile = true;
        }
    }

    
    
    while(!WordNotFound && !EndFile && !Empty)
    {
        QueueStackSize = QueueStack.size(); // saves current queue size
        VectorWords = Vector;               // save vector words
        VectorSize = Vector.size();         // save vector size
        Vector.clear();                     // reset vector
        
        
        
        for(int i=0; i<VectorSize && !EndFile; i++)
        {
            findWords(VectorWords.at(i), end);
            
           
            long StaticVectorSize = static_cast<int>(Vector.size());
            for(int i=0; i< StaticVectorSize; i++)
            {
                if(Vector.at(i)==end)
                {
                    EndFile = true;
                }
            }
            
            QueueStack.pop();
            
            if(QueueStack.size()!=0)
            {
                Stack = QueueStack.front();
                Stack.pop();
            }
        }
        
        
        long StaticQueueStackSize = static_cast<int>(QueueStack.size());
        if (StaticQueueStackSize == QueueStackSize)
        {
            WordNotFound = true;
        }
        
        if(QueueStack.size()==0)
        {
            Empty = true;
        }
        
        
    }
    
    if(EndFile)
    {
       return true;
       
        
    }
 
    return false;
}