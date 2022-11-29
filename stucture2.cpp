#include <iostream>
#include <math.h>

struct Rdec2D {
	double x = 0.0;
	double y = 0.0;
};

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& v) {  
	return ostrm << '(' << v.x << ',' << v.y<< ')';
}

Rdec2D operator+=(Rdec2D& lhs, const Rdec2D& rhs) { 
	lhs.x += rhs.x;    
	lhs.y += rhs.y;                        
	return lhs;
}
Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	return res;
}

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs) { 
	Rdec2D res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	return res;
}

Rdec2D operator*(const Rdec2D& lhs, int chi) {     
	Rdec2D res;
	res.x = lhs.x*chi;
	res.y = lhs.y*chi;
	return res;
}

Rdec2D operator/(const Rdec2D& lhs, int chid) {       
	Rdec2D res;
	res.x = lhs.x / chid;
	res.y = lhs.y / chid;
	return res;
}

Rdec2D operator==(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res1;
	res1.x = 1;
	res1.y = 1;
	Rdec2D res0;
	res0.x = 0;
	res0.y = 0;
	if ((lhs.x == rhs.x)&(rhs.y == lhs.y)) {
		return res1;
	}
	else {
		return res0;
	}
}

Rdec2D operator!=(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res1;
	res1.x = 1;
	res1.y = 1;
	Rdec2D res0;
	res0.x = 0;
	res0.y = 0;
	if ((lhs.x != rhs.x) || (lhs.y != rhs.y)) {
		return res1;
	}
	else {
		return res0;
	}
}
double Dot(const Rdec2D& lhs, const Rdec2D& rhs) {
	double res;
	res = lhs.x * rhs.x + lhs.y * rhs.y;
	return res;
}

double Norm(const Rdec2D& lhs) {
	double res;
	res = sqrt(lhs.x*lhs.x + lhs.y*lhs.y);
	return res;
}

int main() {
	Rdec2D v;
	Rdec2D v2;
	Rdec2D v3;
	Rdec2D k;
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