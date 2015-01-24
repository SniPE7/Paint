#include "stdafx.h"
#include "Figure.h"
//!!5 b
IMPLEMENT_SERIAL(Figure, CObject, 1)
//IMPLEMENT_SERIAL(RectangleM, CObject, 1)
IMPLEMENT_SERIAL(EllipseM, CObject, 1)
//!!5 e
Figure::Figure(void)
{
}

Figure::Figure(const Figure &f)
{
	if (&f != this)
	{
		x1 = f.x1;
		x2 = f.x2;
		y1 = f.y1;
		y2 = f.y2;
	}
}

const Figure&Figure::operator=(const Figure &f)
{
	if (&f != this)
		Figure(f);
	return *this;
}

Figure::~Figure(void)
{
}
//!!5
RectangleM::RectangleM(){}
RectangleM::RectangleM(const RectangleM &r) : Figure(r.x1, r.y1, r.x2, r.y2){}
const RectangleM&RectangleM::operator=(const RectangleM &r)
{
	if (&r != this)
		RectangleM(r);
	return *this;
}
//!!5
EllipseM::EllipseM(){}
EllipseM::EllipseM(const EllipseM &e) : Figure(e.x1, e.y1, e.x2, e.y2){}
const EllipseM&EllipseM::operator=(const EllipseM &e)
{
	if (&e != this)
		EllipseM(e);
	return *this;
}