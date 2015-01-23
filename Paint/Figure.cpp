#include "stdafx.h"
#include "Figure.h"
//!!5 b
IMPLEMENT_SERIAL(Figure, CObject, 1)
IMPLEMENT_SERIAL(RectangleM, CObject, 1)
IMPLEMENT_SERIAL(EllipseM, CObject, 1)
//!!5 e
Figure::Figure(void)
{
}

Figure::~Figure(void)
{
}
//!!5
RectangleM::RectangleM(){}
//!!5
EllipseM::EllipseM(){}