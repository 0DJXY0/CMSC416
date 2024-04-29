/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ int numChares;
/*readonly*/ CProxy_Prefix prefixArray;
/*readonly*/ int numPhases;
/*readonly*/ int numDone;

#include <iostream>
#include "prefix.decl.h"
#include <vector>
#include <fstream>
#include <cmath>

class Main: public CBase_Main {
  //private:
  //std::string file_name; 
public:
  Main(CkArgMsg* msg){
    
    std::string input_file_name = atoi(msg->argv[1]);
    numChares =  atoi(msg->argv[2]);
    std::string output_file_name = atoi(msg->argv[3]);
    numDone = 0;
    mainProxy = thisProxy;
    prefixArray = CProxy_Prefix::ckNew(numChares);
    std::ifstream file(input_file_name);
    if (!file.is_open()){
      std::cerr << "Failed to open file\n";
      return 1;
    }
    std::vector<int> numbers;
    int number;
    while (file >> number) {
      numbers.push_back(number);
    }
    int grid_size = sizeof(numbers)/numChares;
    numPhases = 0;
    while (pow(2,numPhases) < sizeof(numbers)){
	numPhases++;
    }
      
    //std::vector<int> subtask;
    for (int i=0;i<numChares;i++){
      std::vector<int> subtask(numbers.begin()+i*grid_size,numbers.begin()+(i+1)*grid_size);
      if (i == numChares-1){
	std::vector<int> subtask(numbers.begin()+i*grid_size,numbers.end());
      }
      prefixArray[i] = CProxy_Prefix::ckNew(subtask);
    }
    
  }
  void done(void){
    ckout << "All done" << endl;
    CkExit();
  }
  
  
};
  

class Prefix: public CBase_Prefix{
public:
  Prefix(std::vector<int> subtask){
    int current_phase = 0;
    std::vector<int>subtask = subtask;
    int length_subtask = subtask.size();	  
    for (int i=1;i<length_subtask;i++){
      subtask[i] = subtask[i-1];
    }
    int current_value = subtask[length_subtask-1];
  }

  void phase(int current_phase){
    int targetIndex = thisIndex + (1 << current_phase);
    
    if (targetIndex < numChares){
      thisProxy[targetIndex].passValue(current_phase, current_value);
    }
    else{
      numDone++;
      if (numDone == numChares) main_Proxy.done();
    }    
      
  }

  void passValue(int phase, int value){     
    for (int i=0;i<length_subtask;i++){
      subtask[i] = subtask[i] + value;
    }
    current_phase = phase+1;
    current_value = subtask[length_subtask-1];
    if (phase != numPhases - 1){
      phase(current_phase);
    }
    else{
      numDone++;
    }
     
  }
      
      
};

  
    
#include "prefix.def.h"
