/*
 * Class GMM: interface to do GMM/UBM training, GMM adaptation and file input/output
 *
 * 1. Estimate UBM using EM algorithm
 * 2. Adapt a speaker GMM from UBM
 * 3. Scoring against a GMM given a series of features
 * 4. Save/Load interface to files
 *
 * BTW: a log_add_exp function is also provided here that one may need it to calculate the expression:
 *      log(A+B) given log(A) and log(B)
 *
 * Author: Bill Liu
 * Date: 1/18/2015
 */

#ifndef __GMM_H__
#define __GMM_H__

#include <armadillo>
#include <vector>

double log_add_exp(double a, double b);

class GMM{
private:
	int m_nMixture;
	int m_nDimension;
	arma::vec m_Weights;
	std::vector<arma::vec> m_Means;
	std::vector<arma::vec> m_Precisions;
	arma::gmm_diag m_Model;

public:
	GMM();

	GMM(const int mixture, const int dimension);

	GMM(const arma::gmm_diag& model);

	GMM(const GMM& other);
	
	GMM& operator=(const GMM& other);

	bool Load(const std::string& filename);
	bool Save(const std::string& filename) const;

	// Change the parameter of GMM should be careful

	int Gaussians() const { return m_nMixture; }
	int& Gaussians() { return m_nMixture; }

	int Dimension() const { return m_nDimension; }
	int& Dimension() { return m_nDimension; }

	const arma::vec& Weights() const { return m_Weights; }
	const std::vector<arma::vec>& Means() const { return m_Means; }
	const std::vector<arma::vec>& Precisions() const { return m_Precisions; }
	const arma::gmm_diag& Model() const { return m_Model; }
	
	double Estimate(const arma::mat dataset, const int km_iter=10, const int em_iter=10, const float tolerance=1e-10);
	
	bool Adapt(const arma::mat dataset, const float relevance=16.0);

	double LogLikelihood(const arma::mat dataset);

	bool Statistics(const arma::fmat dataPoints, std::vector<double> &accpmt, std::vector<arma::vec> &accpmtx);
};

#endif
