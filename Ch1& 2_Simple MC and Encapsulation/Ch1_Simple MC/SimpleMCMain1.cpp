// requies Random1.cpp
#include "Random1.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include "SimpleMC.h"



double SimpleMonteCarlo1(double Expiry,
						 double Spot,
						 double Strike,
						 double vol,
						 double r,
						 unsigned long NumberOfPath) {
	double Spot_T, PayOff;
	double SumPayOff = 0.0;
	for (unsigned long i = 0; i < NumberOfPath; ++i) {
		Spot_T = Spot * exp((r - 0.5 * vol * vol) * Expiry + vol * sqrt(Expiry) * GetOneGaussianByBoxMuller());
		PayOff = std::max(Spot_T - Strike, 0.0);
		SumPayOff += PayOff;
	}
	double mean = SumPayOff / NumberOfPath;
	return mean * exp(-r * Expiry);
}

int main() {
	double Spot, Strike, Expiry, Vol, R, NumberOfPath;
	std::cout << "Please enter Spot, Strike, Expiry, Vol, R, NumberOfPath: \n";
	std::cin >> Spot;
	std::cin >> Strike;
	std::cin >> Expiry;
	std::cin >> Vol;
	std::cin >> R;
	std::cin >> NumberOfPath;
	PayOff callPayOff{ Strike, PayOff::call };
	PayOff putPayOff{ Strike, PayOff::put};
	PayOff digitalCallPayOff{ Strike, PayOff::digitalcall_CashOrNothing };

	double callValue = SimpleMC(callPayOff, Expiry, Spot, R, Vol, NumberOfPath);
	double putValue = SimpleMC(putPayOff, Expiry, Spot, R, Vol, NumberOfPath);
	double digitalcallValue = SimpleMC(digitalCallPayOff, Expiry, Spot, R, Vol, NumberOfPath);

	std::cout << "call option value is: " << callValue << std::endl;
	std::cout << "put option value is: " << putValue << std::endl;

	// verify if pricer is aline with put-call parity C - P = S - Ke^(-rT)
	double LeftHand = callValue - putValue;
	double RightHand = Spot - Strike * exp(-R * Expiry);
	std::cout << "Put call Parity C - P = S - Ke^(-rT) \n";
	std::cout << "C - P: " << LeftHand << " " << "S - Ke^(-rT): " << RightHand << std::endl;
	return 0;
}