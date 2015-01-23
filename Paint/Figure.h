// instead of the triple
// #ifndef ... 
// #define ...
// #endif
// use:
#pragma once   

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
			//!!7 //ar << KIND;
		}
		else // Loading, not storing
		{
			ar >> x1;
			ar >> x2;
			ar >> y1;
			ar >> y2;
			//!!7 //ar >> KIND;
		}
	}
	//!!5 e
protected:
public:
	int x1, y1, x2, y2;//!!7 //,KIND;
	Figure();
	Figure(int xx1, int yy1, int xx2, int yy2)
	{
		x1 = xx1;
		x2 = xx2;
		y1 = yy1;
		y2 = yy2;
	}
	//!!5 for Serialization
	// NOT PURE !!!  
	virtual void Draw(CDC *dc){}
	virtual ~Figure(void);
};

class RectangleM :public Figure{
	//!!5 b
	DECLARE_SERIAL(RectangleM)   //!!! NO ";"     
	//!!5 e
public:
	RectangleM(); //!!5 must 
	RectangleM(int xx1, int yy1, int xx2, int yy2)
		:Figure(xx1, yy1, xx2, yy2)
	{
		//!!7 //KIND=0;
	}
	void Draw(CDC *dc)
	{
		dc->Rectangle(x1, y1, x2, y2);
	}
};
class EllipseM :public Figure{
	//!!5 b
	DECLARE_SERIAL(EllipseM)   //!!! NO ";"     
	//!!5 e
public:
	EllipseM();  //!!5 must
	EllipseM(int xx1, int yy1, int xx2, int yy2)
		:Figure(xx1, yy1, xx2, yy2)
	{
		//!!7 //KIND=1;
	}
	void Draw(CDC *dc)
	{
		dc->Ellipse(x1, y1, x2, y2);
	}
};