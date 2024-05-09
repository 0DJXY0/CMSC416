#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "mpi.h"
#include <csignal>
using namespace std;

void read_input_file(int **life, string const &input_file_name) {

    // Open the input file for reading.                                                                                             
    ifstream input_file;
    input_file.open(input_file_name);
    if (!input_file.is_open())
        perror("Input file cannot be opened");

    string line, val;
    int x, y;
    while (getline(input_file, line)) {
        stringstream ss(line);

        // Read x coordinate.                                                                                                       
        getline(ss, val, ',');
        x = stoi(val);

        // Read y coordinate.                                                                                                       
        getline(ss, val);
        y = stoi(val);

        // Populate the life matrix.                                                                                                
        life[x][y] = 1;
    }
    input_file.close();
}
/*                                                                                                                                  
 * Writes out the final state of the 2D matrix to a csv file.                                                                       
 */
void write_output(int **result_matrix, int X_limit, int Y_limit,
                  string const &input_name, int num_of_generations) {

    // Open the output file for writing.                                                                                            
    ofstream output_file;
    string input_file_name = input_name.substr(0, input_name.length() - 5);
    output_file.open(input_file_name + "." + to_string(num_of_generations) +
                    ".csv");
    if (!output_file.is_open())
        perror("Output file cannot be opened");

    // Output each live cell on a new line.                                                                                         
    for (int i = 0; i < X_limit; i++) {
        for (int j = 0; j < Y_limit; j++) {
            if (result_matrix[i][j] == 1) {
                output_file << i << "," << j << "\n";
            }
        }
    }
    output_file.close();
}



/*                                                                                                                                  
 * Processes the life array for the specified number of iterations.                                                                 
 */
void compute(int **life, int **previous_life, int X_limit, int Y_limit) {
    int neighbors = 0;

    // Update the previous_life matrix with the current life matrix state. 
    
    for (int i = 0; i < X_limit; i++) {
        for (int j = 0; j < Y_limit; j++) {
            previous_life[i + 1][j + 1] = life[i][j];
        }
    }

    // For simulating each generation, calculate the number of live                                                                 
    // neighbors for each cell and then determine the state of the cell in                                                          
    // the next iteration.                                                                                                          
    for (int i = 1; i < X_limit + 1; i++) {
        for (int j = 1; j < Y_limit + 1; j++) {
            neighbors = previous_life[i - 1][j - 1] + previous_life[i - 1][j] +
            previous_life[i - 1][j + 1] + previous_life[i][j - 1] +
            previous_life[i][j + 1] + previous_life[i + 1][j - 1] +
            previous_life[i + 1][j] + previous_life[i + 1][j + 1];

            if (previous_life[i][j] == 0) {
                // A cell is born only when an unoccupied cell has 3 neighbors.                                                     
                if (neighbors == 3)
                    life[i - 1][j - 1] = 1;
            } else {
                // An occupied cell survives only if it has either 2 or 3 neighbors.                                                
                // The cell dies out of loneliness if its neighbor count is 0 or 1.                                                 
                // The cell also dies of overpopulation if its neighbor count is 4-8.                                               
                if (neighbors != 2 && neighbors != 3) {
                    life[i - 1][j - 1] = 0;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {


    if (argc != 7)
        perror("Expected arguments: ./life <input_file> <num_of_generations> <X_limit> <Y_limit> <X dim> <Y dim>");
 
    string input_file_name = argv[1];
    int num_of_generations = stoi(argv[2]);
    int X_limit = stoi(argv[3]);
    int Y_limit = stoi(argv[4]);
    int Xprocs = stoi(argv[5]);
    int Yprocs = stoi(argv[6]);
    int xsize = X_limit/Xprocs;
    int ysize = Y_limit/Yprocs;

    int myid, numprocs;
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Status status;
    MPI_Request requests[8];
    int *sendbuf = (int*)malloc(X_limit*Y_limit*sizeof(int));
    int rbuf[xsize*ysize];
    int ind;
    double starttime, endtime, localtime;
    for (int i = 0; i < 8; i++) {
      requests[i] = MPI_REQUEST_NULL;
    }

    if (myid ==0){
      int **life = new int *[X_limit];
      for (int i = 0; i < X_limit; i++) {
	life[i] = new int[Y_limit];
        for (int j = 0; j < Y_limit; j++) {
	  life[i][j] = 0;
        }
      }
      read_input_file(life, input_file_name);
     

      for (int xx = 0; xx < Xprocs; xx++){
	//cout << "row " << xx << " start\n";
	for (int yy = 0; yy < Yprocs; yy++){
	  //for (int index = 0; index < xsize*ysize; index++) {	    
	  for (int i = 0; i < xsize; i++){
	    for (int j = 0; j < ysize; j++){
	    //ind = (xx*Yprocs + yy)*xsize*ysize + index;
	    //int i = xx*xsize + (ind/ysize - (xx*Yprocs + yy)*xsize);
	    //int j = yy*ysize + ind%ysize;
	    //cout << "ind: "<< ind << " indices: " << i << ' ' << j << " \n";
	      ind = (xx*Yprocs + yy)*xsize*ysize + (i*ysize + j);
	      //if (xx*xsize + i == 4 &&yy*ysize + j < ysize){
		//cout << "ind: "<< ind << " indices: " << xx << ' ' << yy << ' ' << xx*xsize + i << ' ' << yy*ysize + j << ' ' << life[xx*xsize + i][yy*ysize + j] << " \n";}
	      sendbuf[ind] = life[xx*xsize + i][yy*ysize + j];
	    }
	  }
	}
      }  
    }
    int **previous_block = new int *[xsize+2];
    for (int i = 0; i < xsize+2; i++) {
      previous_block[i] = new int[ysize+2];
      for (int j = 0; j < ysize+2; j++) {
	previous_block[i][j] = 0;
      }
    }
    
    MPI_Scatter(sendbuf,xsize*ysize,MPI_INT,rbuf,xsize*ysize,MPI_INT,0,MPI_COMM_WORLD);

    int **block = new int *[xsize];
    for (int i = 0; i < xsize; i++) {
      block[i] = new int[ysize];
      for (int j = 0; j < ysize; j++) {
	ind = i*ysize + j;
	block[i][j] = rbuf[ind];
      }
      
    }
    int *ydata1 = new int[ysize];
    int *ydata2 = new int[ysize];
    int *xdata1 = new int[xsize];
    int *xdata2 = new int[xsize];
    int *xsend1 = new int[xsize];
    int *xsend2 = new int[xsize];

    MPI_Barrier(MPI_COMM_WORLD);
    starttime = MPI_Wtime();
    //num_of_generations = 2;
    for (int numg = 0; numg < num_of_generations; numg++) {
      //if not first row
      if (myid >= Yprocs){
	//cout << "id: " << myid << "\n";
	MPI_Irecv(ydata2, ysize, MPI_INT, myid-Yprocs, 0, MPI_COMM_WORLD, &requests[0]);	    
	MPI_Isend(block[0], ysize, MPI_INT, myid-Yprocs, 0, MPI_COMM_WORLD, &requests[1]);
      }
      if (myid<numprocs-Yprocs){	
	MPI_Irecv(ydata1, ysize, MPI_INT, myid+Yprocs, 0, MPI_COMM_WORLD, &requests[2]);
	MPI_Isend(block[xsize-1], ysize, MPI_INT, myid+Yprocs, 0, MPI_COMM_WORLD, &requests[3]);
      }
      if (myid % Yprocs != 0){
	MPI_Irecv(xdata2, xsize, MPI_INT, myid-1, 0, MPI_COMM_WORLD,&requests[4]);
	for (int i=0;i<xsize;i++){
	  xsend1[i] = block[i][0];
	}
	MPI_Isend(xsend1, xsize, MPI_INT, myid-1, 0, MPI_COMM_WORLD, &requests[5]);
      }
      if(myid % Yprocs !=Yprocs-1){
	MPI_Irecv(xdata1, xsize, MPI_INT, myid+1, 0, MPI_COMM_WORLD, &requests[6]);
	for (int i=0;i<xsize;i++){
	  xsend2[i] = block[i][ysize-1];
	}
	MPI_Isend(xsend2, xsize, MPI_INT, myid+1, 0, MPI_COMM_WORLD, &requests[7]);
      }
      if (myid<numprocs - Yprocs){
	MPI_Wait(&requests[2],MPI_SUCCESS);
        for (int i = 0; i < ysize; i++) {
          previous_block[xsize+1][i+1] = ydata1[i];}
	MPI_Wait(&requests[3],MPI_SUCCESS);
      }
      if (myid>=Yprocs){
	MPI_Wait(&requests[0],MPI_SUCCESS);
	for (int i = 0; i < ysize; i++) {
          previous_block[0][i+1] = ydata2[i];}
	MPI_Wait(&requests[1],MPI_SUCCESS);
      }
      if (myid % Yprocs !=0){
	MPI_Wait(&requests[4],MPI_SUCCESS);
	for (int i = 0; i < xsize; i++) {
          previous_block[i+1][0] = xdata2[i];}
        MPI_Wait(&requests[5],MPI_SUCCESS);
      }
      if (myid % Yprocs != Yprocs-1){
	MPI_Wait(&requests[6],MPI_SUCCESS);
	for (int i = 0; i < xsize; i++) {
          previous_block[i+1][ysize+1] = xdata1[i];}
        MPI_Wait(&requests[7],MPI_SUCCESS);
      }
      compute(block,previous_block,xsize,ysize);  
    }
    
    endtime = MPI_Wtime();
    localtime = endtime - starttime;
    double avg, max, min;
    MPI_Reduce(&localtime,&avg,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
    MPI_Reduce(&localtime,&max,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);
    MPI_Reduce(&localtime,&min,1,MPI_DOUBLE,MPI_MIN,0,MPI_COMM_WORLD);
    avg = avg/numprocs;
    
    for (int i = 0; i < xsize; i++) {
      for (int j = 0; j < ysize; j++) {
        ind = i*ysize + j;
	//cout << rbuf[ind] << "\n";
        rbuf[ind] = block[i][j];
      }
    }
    MPI_Gather(rbuf, xsize*ysize, MPI_INT,sendbuf, xsize*ysize, MPI_INT, 0, MPI_COMM_WORLD);    
    if (myid == 0){
      int **life = new int *[X_limit];
      for (int i = 0; i < X_limit; i++) {
        life[i] = new int[Y_limit];
	for (int j = 0; j < Y_limit; j++) {
	  life[i][j] = 0;
	}
      }
      cout << "prepare output";
      for (int xx = 0; xx < Xprocs; xx++) {
        for (int yy = 0; yy < Yprocs; yy++) {
	  for (int i = 0; i < xsize; i++){
	    for (int j = 0; j < ysize; j++){
	      ind = (xx*Yprocs + yy)*xsize*ysize + (i*ysize + j);
	      //cout << ind << ' '<< xx << ' ' << yy << ' ' << i << ' ' << j << ' ' << sendbuf[ind] << " \n";
	      life[xx*xsize + i][yy*ysize + j] = sendbuf[ind];	      
	    }
	  }
	}
      }
      
      cout << "TIME: Min: " <<  min  << " s Avg: " << avg  << " s Max: " << max << " s\n";

       write_output(life, X_limit, Y_limit, input_file_name, num_of_generations);
    }
    
    MPI_Finalize();
    for (int i = 0; i < xsize; i++) {
      delete block[i];
    }

    for (int i = 0; i < xsize+2; i++) {
      delete previous_block[i];
    }
    
    delete[] previous_block;
    delete[] block;

    
    return 0;
}
