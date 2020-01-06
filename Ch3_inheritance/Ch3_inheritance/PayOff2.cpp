#include "PayOff2.h"

PayOffCall::PayOffCall(double Strike_): Strike(Strike_)
{
}

double PayOffCall::operator()(const double & Spot)
{
	return Spot - Strike > 0 ? Spot - Strike, 0;
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

double PayOffPut::operator()(const double & Spot)
{
	return Spot - Strike < 0 ? Strike - Spot, 0;
}
