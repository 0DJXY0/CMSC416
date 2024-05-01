#include <iostream>
#include "prefix.decl.h"
#include <vector>
#include <fstream>
#include <cmath>
#include <bit>
#include <bitset>

/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ int numChares;
/*readonly*/ CProxy_Prefix prefixArray;
/*readonly*/ int numPhases;
/*readonly*/ int numDone;

class Main: public CBase_Main {
private:
  //numChares = atoi(msg->argv[2]);
  std::string output_file_name;
  double start_time;
  double end_time;
public:
  Main(CkArgMsg* msg){
    
    std::string input_file_name = (msg->argv[1]);
    numChares =  atoi(msg->argv[2]);
    output_file_name = (msg->argv[3]);
    numDone = 0;
    mainProxy = thisProxy;
    prefixArray = CProxy_Prefix::ckNew(numChares);
    std::ifstream input_file;
    input_file.open(input_file_name);
    if (!input_file.is_open()){
      std::cerr << "Failed to open file\n";
    }
    std::string line;
    std::vector<int> numbers;
    while (input_file >> line) {
      int number;
      number = stoi(line);
      numbers.push_back(number);
    }
    input_file.close();
    std::cout << "total number of inputs: " << numbers.size() << "\n";
    int grid_size = numbers.size()/numChares;
    numPhases = 0;
    while (pow(2,numPhases) < numChares){
	numPhases++;
    }
    start_time = CkWallTimer();  
    for (int i=0;i<numChares;i++){
      std::vector<int> subtask(numbers.begin()+i*grid_size,numbers.begin()+(i+1)*grid_size);
      std::cout << subtask[0] << endl;
      if (i == numChares-1){
	std::vector<int> subtask(numbers.begin()+i*grid_size,numbers.end());
      }
      prefixArray[i].receive(subtask);
    }
    std::cout << "I do nothing\n" << endl;
    mainProxy.done();
  }
  void done(void){
    //std::ofstream output_file;
    //output_file.open(output_file_name);
    end_time = CkWallTimer();
    std::cout << "Time taken: " << (end_time - start_time) << "\n";
    prefixArray[0].write(output_file_name);
    
    //ckout << "All done" << endl;
    //CkExit();
  }
  
  
};
  

class Prefix: public CBase_Prefix{
private:
  
  int current_phase = 0;
  std::vector<int>subtask;
  int length_subtask = 0;
  int current_value = 0;
  int numWait = 0;
  int received = 0;
  std::vector<int>buffer;
public:
  Prefix(void){
  }
  
  void receive(std::vector<int> array){
    
    subtask = array;
    length_subtask = subtask.size();
    //std::cout << thisIndex << "has length " << length_subtask << "\n";
    for (int i=1;i<length_subtask;i++){
      subtask[i] = subtask[i] + subtask[i-1];
      //if (thisIndex == 0){
      //std::cout << subtask[i] << "\n"; }
    }
    current_value = subtask[length_subtask-1];
    int index = thisIndex + 1;
    while (index >>= 1) ++numWait;
    //std::cout << "chare " << thisIndex << " start phase 0\n" ;
    phase(0);  
  }

  void write(std::string output_file_name){
    //int index = thisIndex + 1;
    //while (index >>= 1) ++numWait;
    //std::cout << thisIndex << "has to wait " << numWait << "times" << "\n";
    std::ofstream output_file;
    output_file.open(output_file_name, std::ofstream::app);
    //std::cout << "Chare " << thisIndex << " is writing\n" << endl;
    for (int i=0;i<length_subtask;i++){
      output_file << subtask[i] << "\n";
    }
    //std::cout << thisIndex << " has length " << length_subtask << "\n" << endl;
    output_file.close();
    if (thisIndex != numChares-1){
      prefixArray[thisIndex + 1].write(output_file_name);
    }
    else{
      //output_file.close();
      std::cout << "All done\n" << endl;
      CkExit();
    }
  }
  
  void phase(int current_phase){
    
    int targetIndex = thisIndex + (1 << current_phase);
    //std::cout << "Chare " << thisIndex << "received " << received << "current pahse is " << current_phase << "\n";
    //if (received >= current_phase){
      
      
    if (targetIndex < numChares){
      std::cout << "this Chare: "<< thisIndex << " target: " << targetIndex << " current_phase: " << current_phase << " num received: " << received << " should wait: " << numWait << "\n";
      prefixArray[targetIndex].passValue(current_phase, current_value);
      if (received == numWait){
	if (current_phase < numPhases) phase(current_phase+1);
	else numDone++; 
      }
	    
    }
    else{
      if (current_phase == numPhases){
      numDone++;
      if (numDone == numChares) mainProxy.done();
      }      
    }    
    //}

    
  }

  void passValue(int Myphase, int value){     
    //std::cout << "Chare " << thisIndex << " is passed value " << "receive " << received << " Myphase is " << Myphase << "total phase: "<< numPhases <<"\n";
  for (int i=0;i<length_subtask;i++){
      subtask[i] = subtask[i] + value;
    }
  received ++;
  //std::cout << "Chare " << thisIndex << " is passed value " << "receive " << received << " Myphase is " << Myphase << "total phase: "<< numPhases <<"\n";
  current_phase = Myphase + 1;
  current_value = subtask[length_subtask-1];
  std::cout << "Chare " << thisIndex << " is passed value " << "receive " << received << " current phase is "<< Myphase << " Next phase is " << current_phase << " total phase: "<< numPhases <<"\n";
  phase(current_phase);
  
     
  }
      
    
};

  
    
#include "prefix.def.h"
