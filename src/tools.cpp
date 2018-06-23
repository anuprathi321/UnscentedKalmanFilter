#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {


	VectorXd rmse(4);
	rmse << 0,0,0,0;

	if(estimations.size() == 0 || estimations.size() != ground_truth.size())
		return rmse;

	for(unsigned int i = 0; i < estimations.size(); i++)
	{
		VectorXd resd = ground_truth[i] - estimations[i];

		resd = resd.array() * resd.array();
		rmse = rmse + resd;
	}

	rmse = rmse/estimations.size();
	rmse = sqrt(rmse.array());

	return rmse;

}