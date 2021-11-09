#include "WeightDetect.h"
long originalWeight = 0;
bool detectingWeightChanged = false;


void initWeight(long w){
  originalWeight = w;
}

bool startDetectWeightChanged(long w) {
  detectingWeightChanged = true;
}
bool stopDetectWeightChanged() {
  detectingWeightChanged = false;
  originalWeight = 0;
}

bool detectWeightChanged(long w) {
  if(!detectingWeightChanged)
    return false;
  if(w - originalWeight > thresholdWeight || originalWeight - w > thresholdWeight) {
    return true;
  }
  return false;
}
