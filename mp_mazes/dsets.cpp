/* Your code here! */

#include "dsets.h"
using namespace std;

void DisjointSets::addelements(int num) {
  for (int i = 1; i <= num; i++) {
    elements.push_back(-1);
  }
  return;
}

int DisjointSets::find(int elem){
  return 1;
}

void DisjointSets::setunion(int a, int b){

}

int DisjointSets::size(int elem){
  return 1;
}
