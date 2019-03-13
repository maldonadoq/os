#include "../src/point.h"

template<class T> cpoint<T>::cpoint(){	this->x=0;	this->y=0;	}
template<class T> cpoint<T>::cpoint(T _x, T _y){	this->x=_x;	this->y=_y;	}
template<class T> T cpoint<T>::distancexy(){	return this->x-this->y;	}

template<class T> cpoint<T>::~cpoint(){	}

template class cpoint<int>;
template class cpoint<float>;
template class cpoint<double>;