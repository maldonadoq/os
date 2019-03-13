#include <iostream>

#include "src/stat.h"
#include "src/point.h"

using namespace std;

typedef cpoint<double> point;

int main(int argc, char const *argv[]){
	point *a = new point(1.32,2.34);
	
	cout << a->distancexy() << endl;	
	cout << mplus(1,2) << endl;

	delete a;
	return 0;
}