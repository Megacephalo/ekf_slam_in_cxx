#ifndef _MAP_POINT_H_
#define _MAP_POINT_H_

#include <ostream>

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
} /* End of operator << overloading */

#endif /* _MAP_POINT_H_ */