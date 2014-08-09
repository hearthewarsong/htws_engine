#ifndef _HTWS_COLOR_H_
#define _HTWS_COLOR_H_

class Color
{
public:
	double r;
	double g;
	double b;
	double alpha;
public:
	Color();
	Color(double r, double g, double b, double alpha = 1.0);
	Color(int r, int g, int b, int alpha = 255);
	int R() const { return (int)(r * 255);}
	int G() const { return (int)(g * 255);}
	int B() const { return (int)(b * 255);}
	int Alpha() const { return (int)(alpha * 255);}
	void SetR(int r) { this->r = r / 255.0; }
	void SetG(int g) { this->g = g / 255.0; }
	void SetB(int b) { this->b = b / 255.0; }
	void SetAlpha(int alpha) { this->alpha = alpha / 255.0; }
	virtual ~Color();
};

#endif /* _HTWS_COLOR_H_ */
