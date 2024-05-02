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
  std::string output_file_name;
  double start_time;
  double end_time;
  int received = 0;
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
    std::string line;
    std::vector<int> numbers;
    while (input_file >> line) {
      int number;
      number = stoi(line);
      numbers.push_back(number);
    }
    input_file.close();
    int grid_size = numbers.size()/numChares;
    numPhases = 0;
    while (pow(2,numPhases) < numChares){
	numPhases++;
    }
    for (int i=0;i<numChares;i++){
      std::vector<int> subtask(numbers.begin()+i*grid_size,numbers.begin()+(i+1)*grid_size);
      if (i == numChares-1){
	std::vector<int> subtask(numbers.begin()+i*grid_size,numbers.end());
      }
      prefixArray[i].receive(subtask);
    }
  }
  
  void finishLoading(){
    
    received++;
    if (received == numChares){
      start_time = CkWallTimer();
      for (int i=0;i<numChares;i++){
	prefixArray[i].start();
      }
    }
    
  }
  		 
  void done(void){
    numDone = numDone+1;
    if (numDone == numChares){
      end_time = CkWallTimer();
      std::cout << "TIME: " << (end_time - start_time) << " s\n";
      prefixArray[0].write(output_file_name);      
    }       
  }
  
  
};
  

class Prefix: public CBase_Prefix{
private:
  
  int current_phase = 0;
  std::vector<int>subtask;
  int length_subtask = 0;
  int current_value = 0;
  int numWait = 0;
  int AllReceived = 0;
  std::unordered_map<int,int> waitlist;
public:
  Prefix(void){
  }
  
  void receive(std::vector<int> array){
    
    subtask = array;
    length_subtask = subtask.size();
    for (int i=1;i<length_subtask;i++){
      subtask[i] = subtask[i] + subtask[i-1];
    }
    current_value = subtask[length_subtask-1];
    if (thisIndex > 0){
      double log2N = std::log2(thisIndex);
      numWait = std::floor(log2N) + 1;
    }
    mainProxy.finishLoading();
    //std::cout << "chare " << thisIndex << " need to wait " << numWait << "times\n" ;
  }
  void start(){
    if (thisIndex < numChares - 1) prefixArray[thisIndex + 1].passValue(0,current_value);
    if (thisIndex == 0){
      prefixArray[thisIndex].phase();
    }
  }
  void write(std::string output_file_name){
    std::ofstream output_file;
    output_file.open(output_file_name, std::ofstream::app);
    for (int i=0;i<length_subtask;i++){
      output_file << subtask[i] << "\n";
    }
    output_file.close();
    if (thisIndex != numChares-1){
      prefixArray[thisIndex + 1].write(output_file_name);
    }
    else{
      CkExit();
    }
 
  }
  void phase(){
    if(current_phase < numWait){
      auto key = waitlist.find(current_phase);
      while (key != waitlist.end()){
	int value = waitlist.at(current_phase);
	for (int i=0;i<length_subtask;i++){
	  subtask[i] = subtask[i] + value;
	}
	waitlist.erase(current_phase);
	current_phase = current_phase + 1;
	int targetIndex = thisIndex + (1 << current_phase);
	if(targetIndex < numChares){
	  current_value = subtask[length_subtask-1];
	  prefixArray[targetIndex].passValue(current_phase,current_value);
	}
	key = waitlist.find(current_phase);
      }
    }
    if(current_phase >= numWait && AllReceived == 0){
      AllReceived = 1;
      current_phase = current_phase + 1;
      int targetIndex = thisIndex + (1 << current_phase);
      while (targetIndex < numChares){
	current_value = subtask[length_subtask-1];
	prefixArray[targetIndex].passValue(current_phase, current_value);
	current_phase = current_phase + 1;
	targetIndex = thisIndex + (1 << current_phase);
      }
      mainProxy.done();
    }
  }

  void passValue(int Phase, int Value){     
    waitlist.emplace(Phase,Value);
    prefixArray[thisIndex].phase();
  }
  
};

  
    
#include "prefix.def.h"
