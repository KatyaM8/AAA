#include <iosfwd>
#include <cmath>

struct Rdec2D {
	double x = 0.0;
	double y = 0.0;
};

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& v) {
	return ostrm << '(' << v.x << ',' << v.y << ')';
};

Rdec2D operator-(const Rdec2D& lhs) {
	Rdec2D res;
	res.x = -lhs.x;
	res.y = -lhs.y;
	return res;
};

Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	return res;
};

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	return res;
};

Rdec2D operator*(const Rdec2D& lhs, double chi) {
	Rdec2D res;
	res.x = lhs.x*chi;
	res.y = lhs.y*chi;
	return res;
};

Rdec2D operator/(const Rdec2D& lhs, double chid) {
	Rdec2D res;
	res.x = lhs.x / chid;
	res.y = lhs.y / chid;
	return res;
};


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
bool operator==(const Rdec2D& lhs, const Rdec2D& rhs) {
	double epsila = pow(10, -10);
	double delta1 = abs(1 - lhs.x / rhs.x);
	double delta2 = abs(1 - lhs.y / rhs.y);
	return (epsila > delta1)&(epsila > delta2);
}
bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs) {
	double epsila = pow(10, -10);
	double delta1 = abs(1 - lhs.x / rhs.x);
	double delta2 = abs(1 - lhs.y / rhs.y);
	return (epsila <= delta1)||(epsila <= delta2);
}
double len(Rdec2D lhs) {
	return std::sqrt(lhs.x*lhs.x + lhs.y*lhs.y);
};
double ang(Rdec2D lhs) {
	return std::atan2(lhs.y, lhs.x);
}





struct Rpol2D {
	double r = 0.0;
	double phi = 0.0;
};
bool operator==(const Rpol2D& lhs, const Rpol2D& rhs) {
	double epsila = pow(10, -10);
	double delta1 = abs(1 - lhs.r / lhs.r);
	return (epsila > delta1)&(lhs.phi - rhs.phi < epsila);
}
bool operator!=(const Rpol2D& lhs, const Rpol2D& rhs) {
	double epsila = pow(10, -10);
	double delta1 = abs(1 - lhs.r / rhs.r);
	return (epsila <= delta1)||(lhs.phi - rhs.phi >= epsila);
}


Rpol2D Rec_to_Pol(Rdec2D vec) {
	Rpol2D ans{ len(vec), ang(vec) };
	return ans;
}

Rdec2D Rec_to_Dec(Rpol2D vec) {
	Rdec2D ans{ vec.r * std::cos(vec.phi), vec.r * std::sin(vec.phi) };
	return ans;
}
