#pragma once
class PayOff {
public:
	enum OptionType {call, put, digitalcall_CashOrNothing, digitalput_CashOrNothing, digitalcall_AssetOrNothing, digitalput_AssetOrNothing};
	PayOff(double Strike_, OptionType TheOptionType_);
	double operator() (double Spot_) const;
private:
	double Strike;
	OptionType TheOptionType;
};