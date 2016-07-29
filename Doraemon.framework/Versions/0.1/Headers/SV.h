/*
 * Class CSV: extract and control file interface for supervector
 *
 * 1. Extract supervector from a UBM and frames of features
 * 2. Read and write from/to file.
 * 
 * Some functions are static member that one can call them without a class instance.
 *
 * Author: Bill Liu
 * Date: 1/18/2015
 */

#ifndef __SV_H__
#define __SV_H__

#include <string>
#include <armadillo>
#include "GMM.h"

using namespace std;

class CSV{
private:
	arma::fvec m_SV;

public:
	bool Extract(const GMM gmm, const arma::fmat dataPoints);
	bool Extract(const GMM gmm, vector<double> accpmt, vector<arma::vec> accpmtx);
	bool Read(const string filename);
	static bool Read(const string filename, arma::fvec& col);
	static bool Read(const string filename, float* ptr);
	bool Write(const string filename);
	const arma::fvec &GetSV() const { return m_SV; }
	inline int GetDim()
	{
		return m_SV.n_elem;
	}

	static int GetDim(const string filename);
};

#endif
