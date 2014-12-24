#include "bead.h"

int main()
{
	PathGame g;
	vector<string> x;
	x.push_back(".....");
	x.push_back("..#..");
	printf(g.judge(x).c_str());
}
