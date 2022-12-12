#include <iosfwd>
#include <cmath>

struct Rpol2D {
	double x = 0.0;
	double y = 0.0;
};
struct Rdec2D {
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& v) {
	return ostrm << '(' << v.x << ',' << v.y << ')';
};

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& p) {
	return ostrm << '(' << p.x << ',' << p.y << ',' << p.z << ')';
}

Rpol2D operator-(const Rpol2D& lhs) {
	Rpol2D res;
	res.x = -lhs.x;
	res.y = -lhs.y;
	return res;
};

Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rpol2D res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	return res;
};

Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rpol2D res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	return res;
};

Rpol2D operator*(const Rpol2D& lhs, double chi) {
	Rpol2D res;
	res.x = lhs.x*chi;
	res.y = lhs.y*chi;
	return res;
};

Rpol2D operator/(const Rpol2D& lhs, double chid) {
	Rpol2D res;
	res.x = lhs.x / chid;
	res.y = lhs.y / chid;
	return res;
};


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
bool operator==(const Rpol2D& lhs, const Rpol2D& rhs) {
	double epsila = pow(10, -10);
	double delta1 = abs(1 - lhs.x / rhs.x);
	double delta2 = abs(1 - lhs.y / rhs.y);
	return (epsila > delta1)&(epsila > delta2);
}
bool operator!=(const Rpol2D& lhs, const Rpol2D& rhs) {
	double epsila = pow(10, -10);
	double delta1 = abs(1 - lhs.x / rhs.x);
	double delta2 = abs(1 - lhs.y / rhs.y);
	return (epsila <= delta1)||(epsila <= delta2);
}



Rdec2D operator-(const Rdec2D& lhs) {
	Rdec2D res;
	res.x = -lhs.x;
	res.y = -lhs.y;
	res.z = -lhs.z;
	return res;
};
Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	res.z = lhs.z + rhs.z;
	return res;
};
Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	res.z = lhs.z - rhs.z;
	return res;
};
Rdec2D operator*(Rdec2D& lhs, double chislo) {
	Rdec2D res;
	res.x = lhs.x * chislo;
	res.y = lhs.y * chislo;
	res.z = lhs.z * chislo;
	return res;
};
Rdec2D operator/(const Rdec2D& lhs, double chislo) {
	Rdec2D res;
	res.x = lhs.x / chislo;
	res.y = lhs.y / chislo;
	res.z = lhs.z / chislo;
	return res;
};
double Dot(const Rdec2D& lhs, const Rdec2D& rhs) {
	double res;
	res = lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
	return res;
}
double Norm(const Rdec2D& lhs) {
	double res;
	res = sqrt(lhs.x*lhs.x + lhs.y*lhs.y + lhs.z*lhs.z);
	return res;
}
bool operator==(const Rdec2D& lhs, const Rdec2D& rhs) {
	double epsila = pow(10, -10);
	double delta1 = abs(1 - lhs.x / rhs.x);
	double delta2 = abs(1 - lhs.y / rhs.y);
	double delta3 = abs(1 - lhs.z / rhs.z);
	return (epsila > delta1)&(epsila > delta2)&(epsila>delta3);
}
bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs) {
	double epsila = pow(10, -10);
	double delta1 = abs(1 - lhs.x / rhs.x);
	double delta2 = abs(1 - lhs.y / rhs.y);
	double delta3 = abs(1 - lhs.z / rhs.z);
	return (epsila <= delta1)||(epsila <= delta2)||(epsila <= delta3);
}