#include "PayOff1.h"

PayOff::PayOff(double Strike_, OptionType TheOptionType_): Strike(Strike_), TheOptionType(TheOptionType_)
{
}

double PayOff::operator()(double Spot_) const
{
	if (TheOptionType == call)
		return Spot_ - Strike > 0 ? Spot_ - Strike : 0.0;
	if (TheOptionType == put)
		return Strike - Spot_ > 0 ? Strike - Spot_ : 0.0;
	if (TheOptionType == digitalcall_CashOrNothing)
		return Spot_ - Strike > 0 ? 1.0 : 0.0;
	if (TheOptionType == digitalput_CashOrNothing)
		return Strike - Spot_ > 0 ? 1.0 : 0.0;
	if (TheOptionType == digitalcall_AssetOrNothing)
		return Strike - Spot_ > 0 ? Spot_ : 0.0;
	if (TheOptionType == digitalput_AssetOrNothing)
		return Spot_ - Strike> 0 ? Spot_ : 0.0;	
	else
		throw("Unknown type is found.");
}
