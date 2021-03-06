#include <algorithm>
#include <sstream>
#include <sys/time.h>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <map>
#include <stdint.h>
#include <math.h>
#include <random>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <utility>
#include <vector>

#define AUXILIARY_NODE_ID -1
#define L_CONSTANT 1
#define EPSILON_CONSTANT 0.2
#define K_CONSTANT 10
#define NUM_TRIALS 100
#define NUM_ROWS_PER_BATCH 100000

#define BLOCK_SIZE 512
#define TILE_X_3D 4
#define TILE_Y_3D 16
#define TILE_Z_3D 16
#define TILE_X_2D 32
#define TILE_Y_2D 32

using namespace std;

template <typename T>
struct CSR
{
    vector<T> data;
    vector<int> rows;
    vector<int> cols;
    CSR() : data(), rows(), cols(){};
};

class Benchmark
{
    vector<string> files;
    unordered_set<int> (*nodeSelection)(CSR<float> *graph, int k, double theta);

  public:
    Benchmark();
    unordered_set<int> findKSeeds(CSR<float> *graph, int k);
    void run();
    void setNodeSelectionFunction(unordered_set<int> (*func)(CSR<float> *graph, int k, double theta));
};

class CSVReader
{
    string fileName;
    string delimeter;

  public:
    CSVReader(string filename, string delm = " ") : fileName(filename), delimeter(delm) {}
    vector<vector<string>> getData();
};

unordered_set<int> findKSeeds(CSR<float> *graph, int k);

double nCr(double n, double k);

double calculateLambda(double n, double k, double l, double e);

unordered_set<int> randomReverseReachableSet(CSR<float> *graph);

int width(CSR<float> *graph, unordered_set<int> nodes);

double kptEstimation(CSR<float> *graph, int k);

CSR<float> *covertToCSR(vector<vector<string>> rawData);

bool fileExists(const std::string &name);

unordered_set<int> findKSeeds(CSR<float> *graph, int k);
