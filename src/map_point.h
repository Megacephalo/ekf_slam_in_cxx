#ifndef _MAP_POINT_H_
#define _MAP_POINT_H_

#include <ostream>
#include <vector>

struct MapPoint ;
typedef std::vector<MapPoint> LandmarkSet ;

struct MapPoint {
	MapPoint()
	: id(0)
	, x(0)
	, y(0)
	{} /* End of construcot */

	long long id ;
	float x ;
	float y ;
} ; /* End of struct */

inline std::ostream& operator << (std::ostream& out, const MapPoint& mapPoint) {
	out << std::to_string(mapPoint.id) << ": (" + std::to_string(mapPoint.x) << ", " << std::to_string(mapPoint.y) << ")" ;
	return out ;
} /* End of operator << overloading for MapPoint */

inline std::ostream& operator << (std::ostream& os, const std::vector<MapPoint>& landmarks) {
	std::vector<MapPoint>::const_iterator it ;
	for (it = landmarks.begin() ; it != landmarks.end() ; it++) {
		os << *it << std::endl ;
	}

	return os ;
} /* End of operator << overloading for vector of MapPoints */

#endif /* _MAP_POINT_H_ */