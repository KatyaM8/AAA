#include <iostream>

struct Rpd {
  double z = 0.0;
  double ph = 0.0;
};
struct Rdec {
  int x;
  int y;
};

std::ostream& operator<<(std::ostream& ostrm,                     /*вывод в поток*/
  const Rdec& p) {
  return ostrm << '(' << p.x << ',' << p.y << ')';
}

Rdec operator+(const Rdec& lhs,
  const Rdec& rhs) {
  Rdec res = { 0,0 };
  res = { lhs.x + rhs.x,  rhs.y + lhs.y };
  return res;
}

Rdec operator-(const Rdec& lhs,
  const Rdec& rhs) {
  Rdec res = { lhs.x - rhs.x, lhs.y - rhs.y };
  return res;
}

Rdec operator-(Rdec& p) {
  return { p.x * (-1),p.y * (-1) };
}

Rdec operator*(const Rdec& lhs) {
  Rdec res = { lhs.x * 5.2, lhs.y * 5.2 };
  return res;
}

double norma(const Rdec& vec)
{
  double r;
  r = std::sqrt(vec.x * vec.x + vec.y * vec.y);
  return r;
}

double Dot(const Rdec& lhs, const Rdec& rhs) {
  double pr;
  pr = lhs.x * rhs.x + lhs.y * rhs.y;
  return pr;
}

double toPol(const Rdec& lhs) {
  double PolR;
  PolR = std::sqrt(lhs.x * lhs.x + lhs.y * lhs.y);
  double a;
  a = lhs.y / lhs.x;
  return PolR, a;
}

double toDec(const Rpd& lhs) {
  double pointDecX;
  double pointDecY;
  pointDecX = lhs.z * cos(lhs.ph);
  pointDecY = lhs.z * sin(lhs.ph);
  return pointDecX, pointDecY;
}

int main() {
  Rdec point1{ 3,4 };
  Rdec point2{ 5,7 };
  Rpd vector1{ 30, 15 };
  std::cout << "point1 " << point1 << std::endl;
  auto point3 = point1 + point2;
  std::cout << "point3 " << point3 << std::endl;
  auto point4 = point1 - point2;
  std::cout << "point4" << point4 << std::endl;

  auto point5 = point1;
  std::cout << "point5= " << point5 << std::endl;
  

  /*double len_norm;
  len_norm = norma(point2);
  std::cout <<"Length of vector 2 = " << len_norm << std::endl;

  double proizvedenie;
  proizvedenie = Dot(point1, point2);
  std::cout << "Skalzrnoe proizvedenie 1 and 2 = " << proizvedenie << std::endl;

  double Rpol;
  double alpha;
  Rpol, alpha = toPol(point1);
  std::cout << "Radius =" << Rpol << "  " << " alpha = " << alpha << std::endl;

  double Xdec;
  double Ydec;
  Xdec, Ydec = toDec(point1);
  std::cout << " Koordinati: x = " << Xdec << "  " << " Y = " << Ydec << std::endl;
  */
}
