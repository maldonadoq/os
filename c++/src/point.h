#ifndef _POINT_H_
#define _POINT_H_

template<class T>
class cpoint{
private:
	T x,y;
public:
	cpoint();
	cpoint(T,T);
	T distancexy();
	~cpoint();
};

#endif