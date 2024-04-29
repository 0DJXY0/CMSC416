/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ int numChares;
/*readonly*/ CProxy_Prefix prefixArray;
int flags[numChares];

#include <iostream>
#include "prefix.decl.h"
#include <vector>
#include <fstream>


class Main: public CBase_Main {
  //private:
  //std::string file_name; 
public:
  Main(CkArgMsg* msg){
    
    std::string input_file_name = atoi(msg->argv[1]);
    numChares =  atoi(msg->argv[2]);
    flags = {};
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
    //std::vector<int> subtask;
    for (int i=0;i<numChares;i++){
      std::vector<int> subtask(numbers.begin()+i*grid_size,numbers.begin()+(i+1)*grid_size)
	if (i == numChares-1){
	  std::vector<int> subtask(numbers.begin()+i*grid_size,numbers.end())}
    }
    
  }
  void done(void){
    int count = 0;
    for (int i=0;i<numChares;i++){
      count = count + flags[i];
    }
    if (count == numChares){
    ckout << "All done" << endl;
    CkExit();
    }
  }
  
  
};
  

class Prefix: public CBase_Prefix{
public:
  Prefix(std::vector<int> subtask){
    current_phase = 0;
    std::vector<int>subtask = subtask;
    int length = subtask.size();	  
    for (int i=1;i<length;i++){
      subtask[i] = subtask[i-1];
    }
    current_value = subtask[length-1];
  }

  void phase(int current_phase){
    int targetIndex = thisIndex + (1 << current_phase);
    
    if (targetIndex < numChares){
      thisProxy[targetIndex].passValue(current_phase, current_value);
    }
    else{
      flags[thisIndex] = 1;
    }
    main_Proxy.done();
      
  }

  void passValue(int phase, int value){
    if (phase < numPhases){     
    for (int i=0;i<length;i++){
      subtask[i] = subtask[i] + value;
    }
    current_phase = phase+1;
    current_value = subtask[length-1];
    }
    else{
      flags[thisIndex] = 1;
    }
    phase(current_phase);
     
  }
      
      
}

}
    
