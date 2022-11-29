#include <iostream>

struct Rdec2D {
	double x = 0.0;
	double y = 0.0;
};

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& v) {   //âûâîä â ïîòîê
	return ostrm << '(' << v.x << ',' << v.y<< ')';
}

Rdec2D operator+=(Rdec2D& lhs, const Rdec2D& rhs) { 
	lhs.x += rhs.x;    
	lhs.y += rhs.y;                        //ÏÐÈÑÂÀÈÂÀÞÙÈÅ ÎÏÅÐÀÒÎÐÛ ÂÎÇÂÐÀÙÀÞÒ ÑÑÛËÊÓ ÍÀ ÏÅÐÂÛÉ ÀÐÃÓÌÅÍÒ
	return lhs;
}
Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs) { //ñëîæåíèå äâóõ âåêòîðîâ
	Rdec2D res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	return res;
}

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs) { //âû÷èòàíèå äâóõ âåêòîðîâ
	Rdec2D res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	return res;
}

Rdec2D operator*(const Rdec2D& lhs, int chi) {       //óíîæåíèå âåêòîðà íà ÷èñëî
	Rdec2D res;
	res.x = lhs.x*chi;
	res.y = lhs.y*chi;
	return res;
}

Rdec2D operator*(const Rdec2D& lhs, int chid) {       //äåëåíèå âåêòîðà íà ÷èñëî
	Rdec2D res;
	res.x = lhs.x / chid;
	res.y = lhs.y / chid;
	return res;
}

int main(){
	Rdec2D v;
	Rdec2D v2;
	Rdec2D v3;
	int chi = 0;
	int chid = 0;
	chid = 3;
	chi = 5;
	v.x = 2;
	v.y = 5;
	v2.x = 5;
	v2.y = 3;
	std::cout << v << std::endl << v2 / chid;
}