// instead of the triple
// #ifndef ... 
// #define ...
// #endif
// use:
#pragma once   
#include <string>
using namespace std;
using std::string;

//!!5 for Serialization
class Figure : public CObject
{
	//!!5 b
	DECLARE_SERIAL(Figure)   //!!! NO ";"
public:
	void Serialize(CArchive& ar)
	{
		CObject::Serialize(ar);
		if (ar.IsStoring())
		{
			ar << x1;
			ar << x2;
			ar << y1;
			ar << y2;
			ar << fs;
			//!!7 //ar << KIND;
		}
		else // Loading, not storing
		{
			ar >> x1;
			ar >> x2;
			ar >> y1;
			ar >> y2;
			ar >> fs;
			//!!7 //ar >> KIND;
		}
	}
	//!!5 e
protected:
public:
	int x1, y1, x2, y2, fs;//!!7 //,KIND;
	//int color;
	Figure();
	Figure(int xx1, int yy1, int xx2, int yy2, int frameSize)
	{
		x1 = xx1;
		x2 = xx2;
		y1 = yy1;
		y2 = yy2;
		fs = frameSize;
	}
	//!!5 for Serialization
	// NOT PURE !!!  
	Figure(const Figure &); // copy constuctor
	const Figure &operator=(const Figure &); // assign function

	virtual void Draw(CDC *dc){}
	virtual ~Figure(void);
	virtual string getFigureName();
};

class RectangleM :public Figure{
	//!!5 b
	//DECLARE_SERIAL(RectangleM)   //!!! NO ";"     
	//!!5 e
public:
	RectangleM(); //!!5 must 
	RectangleM(int xx1, int yy1, int xx2, int yy2, int fs)
		:Figure(xx1, yy1, xx2, yy2, fs)
	{
		//!!7 //KIND=0;
	}

	RectangleM(const RectangleM &); // copy constuctor
	const RectangleM &operator=(const RectangleM &); // assign function

	void Draw(CDC *dc)
	{
		dc->Rectangle(x1, y1, x2, y2);
	}
	string getFigureName();
};

class EllipseM :public Figure{
	//!!5 b
	DECLARE_SERIAL(EllipseM)   //!!! NO ";"     
	//!!5 e
public:
	EllipseM();  //!!5 must
	EllipseM(int xx1, int yy1, int xx2, int yy2, int fs)
		:Figure(xx1, yy1, xx2, yy2, fs)
	{
		//!!7 //KIND=1;
	}

	EllipseM(const EllipseM &); // copy constuctor
	const EllipseM &operator=(const EllipseM &); // assign function

	void Draw(CDC *dc)
	{
		dc->Ellipse(x1, y1, x2, y2);
	}
	string getFigureName();

};

class LineM :public Figure{
	//!!5 b
	//DECLARE_SERIAL(LineM)   //!!! NO ";"     
	//!!5 e
public:
	LineM();  //!!5 must
	LineM(int xx2, int yy2, int fs) :Figure(xx2, yy2, xx2, yy2, fs)
	{
		//!!7 //KIND=1;
	}

	LineM(const LineM &); // copy constuctor
	const LineM &operator=(const LineM &); // assign function

	void Draw(CDC *dc)
	{
		dc->LineTo(x1, y2);
	}
	string getFigureName();
};