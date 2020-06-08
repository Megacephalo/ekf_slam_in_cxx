#ifndef _DRAW_H_
#define _DRAW_H_

#include <map>
#include <Eigen/Dense>
#include <cassert>
#include <math.h>
#include <vector>

#include "feature_importer.h"
#include "measurements_importer.h"
#include "sensor_records.h"
#include "chisquare.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

class Draw {
  private:
	std::map<std::string, std::string> l_settings;
	std::map<std::string, std::string> o_settings;
	std::map<std::string, std::string> traj_settings ;

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
				   , const observations& Z) ;
	void draw_trajectory(const std::vector<Eigen::VectorXd>& path, const std::string& color = "magenta") ;
	void draw_trajectory(const std::vector<float>& X, const std::vector<float>& Y, const std::string& color = "magenta") ;
	void Pause(float seconds = 0.01) ;
	void Clear() ;
	void Show() ;
	void Save(std::string path) ;
};

#endif /* _DRAW_H_ */