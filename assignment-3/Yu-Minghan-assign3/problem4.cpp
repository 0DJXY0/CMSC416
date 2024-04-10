#include <stdlib.h>
#include <cmath>
#include <vector>
#include <complex>
#include <omp.h>

#define POINTS_MIN  -1.0
#define POINTS_MAX  1.0

#if !defined(M_PI)
#define M_PI 3.14159265358979323846
#endif

/* Compute the discrete fourier transform of x. Store the result in output.

   Example:
      input: [1, 4, 9, 16]
      output: [30+0i, -8-12i, -10-0i, -8+12i]
*/
void dft(std::vector<double> const& x, std::vector< std::complex<double> > &output) {
    int N = x.size();
    double theta;

    // Allocate memory for the output array
    output.resize(N, std::complex<double>(0, 0));

    for (int k = 0; k < N; k++) {
        std::complex<double> sum(0.0, 0.0);
        for (int n = 0; n < N; n++) {
            theta = 2 * M_PI * k * n / N;
            std::complex<double> c(std::cos(theta), -std::sin(theta));
            sum += x[n] * c;
        }
        output[k] = sum;
    }
}

int main(int argc, char **argv) {
    int N = 1024;
    int seed = 273;

    if (argc == 2) {
        N = std::stoi(argv[1]);
    }
    if (argc == 3) {
	    N = std::stoi(argv[1]);
	    seed = std::stoi(argv[2]);
    }

    std::vector<double> x(N);
    std::vector< std::complex<double> > correct(N), dft_omp(N);
    srand(seed);

    for (int i = 0; i < N; i += 1) {
        x[i] = (rand() / (double) RAND_MAX) * (POINTS_MAX - POINTS_MIN) + POINTS_MIN;
    }

    // double totalTime = 0.0;
    // double start = omp_get_wtime();
    
    dft(x, correct);

    N = x.size();
    double theta;
    
    dft_omp.resize(N, std::complex<double>(0, 0));
    std::complex<double> sum(0.0, 0.0);
    //double totalTime = 0.0;
    //double start = omp_get_wtime();
    std::complex<double> c;
    #pragma omp parallel for private(sum,theta,c)
    for (int k = 0; k < N; k++) {
        sum = std::complex<double>(0.0,0.0);
        for (int n = 0; n < N; n++) {
            theta = 2 * M_PI * k * n / N;
            c = std::complex<double> (std::cos(theta), -std::sin(theta));
	    //std::complex<double> c(std::cos(theta), -std::sin(theta));
	    sum += x[n] * c;
        }
        dft_omp[k] = sum;
    }



    
    bool isCorrect = true;
    for (int j = 0; j < x.size(); j += 1) {
        if (std::abs(correct[j].real() - dft_omp[j].real()) > 1e-4 || std::abs(correct[j].imag() - dft_omp[j].imag()) > 1e-4) {
            isCorrect = false;
            break;
        }
    }

    
    printf("Correct? %s\n", isCorrect?"true":"false");



    
    //totalTime = omp_get_wtime() - start;
    //printf("Time: %.5f\n", totalTime);
}
