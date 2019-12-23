#include "SimpleMC.h"
#include "Random1.h"
#include <cmath>

double SimpleMC(const PayOff & thePayOff, double Expiry, double Spot, double r, double vol, double NumberOfPath)
{

	double Spot_T;
	double PayOffSum = 0.0;
	for (unsigned long i = 0; i < NumberOfPath; ++i) {
		Spot_T = Spot * exp((r - 0.5 * vol * vol) * Expiry + vol * sqrt(Expiry) * GetOneGaussianByBoxMuller());
		double Payoff_singpath = thePayOff(Spot_T);
		PayOffSum += Payoff_singpath;
	}
	double mean_PayOff = PayOffSum / NumberOfPath;
	return mean_PayOff * exp(-r * Expiry);
}
