/*
 * Class CHTK: Interface between HTK feature file and armadillo matrix
 * 
 * Read features from a single HTK file,
 * or one can specify a list to load branches of features at one time 
 * BOTH single- and double-column formats are accepted
 *
 * Author: Bill Liu
 * Date: 1/18/2015
 */

#ifndef __CHTK_H__
#define __CHTK_H__

#include <armadillo>
#include <string>

using namespace std;

typedef struct _HTKFLAG{
	int nSamples;
	int sampPeriod;
	short sampSize;
	short parmKind;
} HTKFLAG;

class CHTK{
private:
	int m_nDim;
	int m_nFrame;
	arma::fmat m_Feature;
public:
	CHTK() : m_nDim(0), m_nFrame(0), m_Feature(arma::fmat(0, 0)) {} 

	int Dimension() const { return m_nDim; }
	int Frame() const { return m_nFrame; }
	const arma::fmat& Feature() const { return m_Feature; }

	bool Read(const string filename);
	static bool Read(const string filename, arma::fmat& feature);
	static bool Read(const string filename, float* pMat, int n_rows, int n_cols);
	static bool Read(const string filename, int& dim, int& frame);
	
	bool ReadList(const string script_list, const string dir="", const string ext="");
	bool ReadList(const vector<string> filenames, const string dir="", const string ext="");
};

#endif
