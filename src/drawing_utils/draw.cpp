#include "draw.h"

void
Draw::Drawellipse(const Eigen::VectorXd& X, float a, float b, std::string color) {
	assert(X.size() == 3);
	const int NPOINTS = 100;
	Eigen::VectorXd vec = Eigen::VectorXd::LinSpaced(NPOINTS, 0, 2 * M_PI);
	int N = vec.size();

	Eigen::MatrixXd p = Eigen::MatrixXd::Ones(2,N);
	p.row(0) = a * vec.array().cos();
	p.row(1) = b * vec.array().sin();

	// //handle the rotation and translation
	float x0 = X(0), y0 = X(1), angle = X(2);
	Eigen::MatrixXd R = Eigen::MatrixXd(2,2);
	R << cos(angle), -sin(angle), sin(angle), cos(angle);

	Eigen::MatrixXd T = Eigen::MatrixXd::Ones(2,N);
	T.row(0) = x0*T.row(0);
	T.row(1) = y0*T.row(1);
	p = R*p + T;

	//for plotting purpuse only
	std::vector<float> Px, Py;
	for (int i = 0; i < N; i++) {
		Px.push_back(p(0,i));
		Py.push_back(p(1,i));
	}
	plt::plot(Px, Py, color);
} /* End of Drawellipse */

void
Draw::Drawprobellipse(Eigen::VectorXd x, const Eigen::MatrixXd& C, float alpha, std::string color) {
	float sxx = C(0, 0), syy = C(1, 1), sxy = C(0, 1);
	float a = sqrt(0.5*(sxx+syy+sqrt(pow(sxx-syy, 2)+4*pow(sxy,2))));   // always greater
	float b = sqrt(0.5*(sxx+syy-sqrt(pow(sxx-syy, 2)+4*pow(sxy,2))));   // always smaller

	//% Scaling in order to reflect specified probability
	a = a*sqrt(chi2invtable(alpha,2));
	b = b*sqrt(chi2invtable(alpha,2));	

	if (sxx < syy) {
	 float temp = a;
	 a = b;
	 b = temp;	
	}

	float angle = 0;
	//% Calculate inclination (numerically stable)
	if (sxx != syy)
	  angle = 0.5*atan(2*sxy/(sxx-syy));	
	else if (sxy == 0)
	  angle = 0;     //angle doesn't matter 
	else if (sxy > 0)
	  angle =  M_PI/4;
	else if (sxy < 0)
	  angle = -M_PI/4;
	x(2) = angle;
	Drawellipse(x,a,b,color);
} /* End of Drawprobellipse */

void
Draw::DrawLandMarks(const Feature_Importer& mapper) {
	std::vector<float> X, Y;
	for (auto& landmark : mapper.landmarks()) {
	X.push_back(landmark.x);
	Y.push_back(landmark.y);
	}
	plt::plot(X, Y, l_settings);
} /* End of DrawLandMarks */


Draw::Draw() {
	//landmarking drawing setting
	l_settings["color"] = "red";
	l_settings["linestyle"] = " ";
	l_settings["marker"] = "+";
	l_settings["markersize"] = "10";
	l_settings["linewidth"] = "5";
	//observation drawing settings;
	o_settings["color"] = "blue";
	o_settings["linestyle"] = " ";
	o_settings["marker"] = "o";
	o_settings["markersize"] = "10";
	o_settings["linewidth"] = "5";
 } /* End of constructor */
 
void
Draw::Plot_state( const Eigen::VectorXd& mu
 				 , const Eigen::MatrixXd& sigma
 				 , const Feature_Importer& mapper
 				 , const std::vector<bool>& observedLandmarks
 				 , std::vector<Observation_model>& Z) 
{
	
	//initia rob pos and landmarks
	Eigen::VectorXd rob = Eigen::VectorXd(3);
	rob << mu(0), mu(1), mu(2);
	Drawprobellipse(rob, sigma, 0.6, "r");
	DrawLandMarks(mapper);

	//DrawLandMarks(landmarks) with probability;
	for(int i = 0; i < observedLandmarks.size(); i++) {
		if(observedLandmarks[i]) {
		    std::vector<float> X, Y;
		    X.push_back(mu(2*i + 3));
		    Y.push_back(mu(2*i + 4));
		    plt::plot(X, Y, o_settings);
		    Eigen::VectorXd m = Eigen::VectorXd(3);
		    m << mu(2*i+3), mu(2*i+4), 0;
		    Eigen::MatrixXd sig = Eigen::MatrixXd(2,2);
		    sig << sigma(2*i+3,2*i+3),sigma(2*i+3, 2*i+4),sigma(2*i+4, 2*i+3),sigma(2*i+4, 2*i+4);
		    Drawprobellipse(m, sig, 0.6, "b");
		}
	}
	
	//draw observation lines
	for(int i= 0; i < Z.size(); i++) {
		std::vector<float> X, Y;
		X.push_back(mu(0)) ; Y.push_back(mu(1)) ;
		X.push_back(mu(2 * Z[i].id() + 1)) ;
		Y.push_back(mu(2 * Z[i].id() + 2)) ;
		plt::plot(X, Y, "k") ;
	}   

	//drawrobot(mu(1:3), 'r', 3, 0.3, 0.3);
	Drawellipse(rob, 0.15, 0.15, "r");
} /* End of Plot_state */

void
Draw::Pause() {
	plt::pause(0.01);
} /* End of Pause */

void
Draw::Clear() {
	plt::clf();
	plt::xlim(-2,12);
	plt::ylim(-2,12);
} /* End of Clear */

void
Draw::Show() {
	plt::show();
} /* End of Show */

void
Draw::Save(std::string path) {
	plt::save(path);
} /* End of Save */