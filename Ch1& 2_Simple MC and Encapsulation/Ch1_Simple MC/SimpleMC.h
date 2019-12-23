#pragma once
#include "PayOff1.h"

double SimpleMC(const PayOff& thePayOff, double Expiry, double Spot, double r, double vol, double NumberOfPath);