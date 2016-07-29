/*
 * Functions that are related to SVM model: read/write/scoring
 * 
 * 1. interface to input from and output to model files
 * 2. calculate expression f(x) = w * x - rho, given that W and rho read from a linear svm model
 *    or use a wrapper to calculate the probability that belong to the target model
 *
 * NOTE: For speaker recognition application, only TWO classes are needed in one SVM model,
 *       so these functions are ONLY support TWO-CLASS svm model input/output. Take care.
 *
 * Author: Bill Liu
 * Date: 1/18/2015
 */

#ifndef __SVMMODEL_H__
#define __SVMMODEL_H__

#include "svm.h"
#include <armadillo>

struct SVMModel{
	int len;        // the length of W
	float *pW;
	float rho;
};

bool save_precomputed_svm_model(const char *filename, const svm_model *model, const arma::fmat &trainSV);
bool save_fx_svm_model(const char *filename, const svm_model *model, float *ptrP, float *ptrN, int nP, int nN, int dim);

bool load_precomputed_svm_model(const char *filename, svm_model *&model, arma::fmat &trainSV);
bool load_fx_svm_model(const char *filename, float **pW, float *rho, int *dim);
bool load_fx_svm_model(const char *filename, SVMModel &model);

float scoring_fx(const float *W, const float rho, const float *x, const int dim);
float scoring_probability(const svm_model *model, const svm_node *x);

#endif
