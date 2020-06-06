#ifndef _BAYESIAN_SLAM_FACTORY_H_
#define _BAYESIAN_SLAM_FACTORY_H_

// #include ""
#include <Eigen/Desne>

class Bayesian_SLAM_factory {
  public:
  	Bayesian_SLAM_factory() ;
  	virtual void initialize() ;
  	virtual Eigen::VectorXd getMean() const = 0 ;
  	virtual Eigen::MatrixXd getCovariance() const = 0 ;
} ; /* End of class */

#endif /* _BAYESIAN_SLAM_FACTORY_H_ */