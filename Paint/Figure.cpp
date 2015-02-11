#include "stdafx.h"
#include "Figure.h"
//!!5 b
IMPLEMENT_SERIAL(Figure, CObject, 1)
IMPLEMENT_SERIAL(RectangleM, CObject, 1)
IMPLEMENT_SERIAL(EllipseM, CObject, 1)
IMPLEMENT_SERIAL(LineM, CObject, 1)
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
		fs = f.fs;
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
RectangleM::RectangleM(const RectangleM &r) : Figure(r.x1, r.y1, r.x2, r.y2, r.fs){}
const RectangleM&RectangleM::operator=(const RectangleM &r)
{
	if (&r != this)
		RectangleM(r);
	return *this;
}
//!!5
EllipseM::EllipseM(){}
EllipseM::EllipseM(const EllipseM &e) : Figure(e.x1, e.y1, e.x2, e.y2, e.fs){}
const EllipseM&EllipseM::operator=(const EllipseM &e)
{
	if (&e != this)
		EllipseM(e);
	return *this;
}

LineM::LineM(){}
LineM::LineM(const LineM &l) : Figure(l.x1, l.y1, l.x2, l.y2, l.fs){}
const LineM&LineM::operator=(const LineM &l)
{
	if (&l != this)
		LineM(l);
	return *this;
}