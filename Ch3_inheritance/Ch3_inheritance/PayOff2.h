#pragma once
class PayOff {
public:
	PayOff() {}
	virtual double operator()(const double& Spot) const = 0;
	virtual ~PayOff() {}
private:
};

class PayOffCall : public PayOff {
private:
	double Strike;
public:
	PayOffCall(double Strike_);
	virtual ~PayOffCall() {}
	virtual double operator()(const double& Spot);
};

class PayOffPut : public PayOff {
private:
	double Strike;
public:
	PayOffPut(double Strike_);
	virtual ~PayOffPut() {}
	virtual double operator()(const double& Spot);
};