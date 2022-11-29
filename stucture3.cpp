#include <iostream>
#include <math.h>

struct Rpol2D {
	double x = 0.0;
	double y = 0.0;
};

std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& v) {  
	return ostrm << '(' << v.x << ',' << v.y<< ')';
}

Rpol2D operator+=(Rpol2D& lhs, const Rpol2D& rhs) { 
	lhs.x += rhs.x;    
	lhs.y += rhs.y;                        
	return lhs;
}
Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rpol2D res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	return res;
}

Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs) { 
	Rpol2D res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	return res;
}

Rpol2D operator*(const Rpol2D& lhs, int chi) {     
	Rpol2D res;
	res.x = lhs.x*chi;
	res.y = lhs.y*chi;
	return res;
}

Rpol2D operator/(const Rpol2D& lhs, int chid) {       
	Rdpol2D res;
	res.x = lhs.x / chid;
	res.y = lhs.y / chid;
	return res;
}

Rpol2D operator==(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rpol2D res1;
	res1.x = 1;
	res1.y = 1;
	Rpol2D res0;
	res0.x = 0;
	res0.y = 0;
	if ((lhs.x == rhs.x)&(rhs.y == lhs.y)) {
		return res1;
	}
	else {
		return res0;
	}
}

Rpol2D operator!=(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rpol2D res1;
	res1.x = 1;
	res1.y = 1;
	Rpol2D res0;
	res0.x = 0;
	res0.y = 0;
	if ((lhs.x != rhs.x) || (lhs.y != rhs.y)) {
		return res1;
	}
	else {
		return res0;
	}
}
double Dot(const Rpol2D& lhs, const Rpol2D& rhs) {
	double res;
	res = lhs.x * rhs.x + lhs.y * rhs.y;
	return res;
}

double Norm(const Rpol2D& lhs) {
	double res;
	res = sqrt(lhs.x*lhs.x + lhs.y*lhs.y);
	return res;
}

Rdec2D ToDec(const Rdec2D& lhs) {
	ede
}

int main() {
	Rpol2D v;
	Rpol2D v2;
	Rpol2D v3;
	Rpol2D k;
	int chi = 0;
	int chid = 0;
	double l;
	chid = 5;
	chi = 5;
	v.x = 2;
	v.y = 5;
	v2.x = 2;
	v2.y = 5;
	l =Norm(v);
	std::cout <<l;
}