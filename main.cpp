#include <iostream>

using namespace std;

int activationFunction(int val, int theta){
  if(val > theta) return 1;
  else if(val < theta) return -1;
  else return 0;
}

int updateWeight(int weight, int learningRate, int target, int inputX){
  return weight + learningRate * target * inputX;
}
int updateBiasWeight(int weight, int learningRate, int target){
  return weight + learningRate * target;
}

int main(){
  /*
    - Data provided as per example discussed in class.
      _______________________
      | X1  | X2  | Target  |
      | 1   | 1   |   1     |
      | 1   | 0   |   -1    |
      | 0   | 1   |   -1    |
      | 0   | 0   |   -1    |
      |_____|_____|_________|
    - bias is 1
    - weight1,weight2 and biasWeight is assumed 0
    - learningRate is 1
  */
  //Variable Declaration
  int inputX1[] = {1,1,0,0}
  ,inputX2[] = {1,0,1,0}
  ,biasX0 = 1
  ,weight1 = 0
  ,weight2 = 0
  ,biasWeight = 0
  ,learningRate = 1
  ,target[4] = {1,-1,-1,-1}
  ,output[4];

  for(int i = 0; true ; i++){
    int netInput = (weight1 * inputX1[i%4]) + (weight2 * inputX2[i%4]) + biasWeight;
    output[i%4] = activationFunction(netInput, 1);
    cout << endl << inputX1[i%4] << " " << inputX2[i%4] << " " << biasX0 << " " << netInput << " " << output[i%4] << " " << target[i%4] << " " << weight1 << " " << weight2 << " " << biasWeight;
    if(output[i%4] != target[i%4]){ 
      weight1 = updateWeight(weight1,learningRate,target[i%4],inputX1[i%4]);
      weight2 = updateWeight(weight2,learningRate,target[i%4],inputX2[i%4]);
      biasWeight = updateBiasWeight(biasWeight,learningRate,target[i%4]);
    }
    if(i%4 == 3 && (output[0] == target[0] && output[1] == target[1] && output[2] == target[2] && output[3] == target[3])) break;
  }

  return 0;
}