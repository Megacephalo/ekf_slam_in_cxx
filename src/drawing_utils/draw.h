#ifndef _DRAW_H_
#define _DRAW_H_

#include <map>
#include <Eigen/Dense>
#include <cassert>
#include <math.h>

#include "feature_importer.h"
#include "measurements_importer.h"
#include "chisquare.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

class Draw {
  private:
	std::map<std::string, std::string> l_settings;
	std::map<std::string, std::string> o_settings;

	void Drawellipse(const Eigen::VectorXd& X, float a, float b, std::string color) ;
	void Drawprobellipse( Eigen::VectorXd x
						, const Eigen::MatrixXd& C
						, float alpha
						, std::string color) ;
	void DrawLandMarks(const Feature_Importer& mapper) ;

  public:
	Draw() ;
	void Plot_state( const Eigen::VectorXd& mu
				   , const Eigen::MatrixXd& sigma
				   , const Feature_Importer& mapper
				   , const std::vector<bool>&observedLandmarks
				   , std::vector<Observation_model>& Z) ;
	void Pause() ;
	void Clear() ;
	void Show() ;
	void Save(std::string path) ;
};

#endif /* _DRAW_H_ */