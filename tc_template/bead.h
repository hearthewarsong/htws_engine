#include <vector>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stdio.h>
#include <set>
#include <queue>
#include <functional>
#include <list>
#include <algorithm>
#include <string>

using std::list;
using std::vector;
using std::set;
using std::string;


class PathGame
{
public:
	bool allempty(vector<string>& board)
	{
		for(unsigned i = 0; i<board[0].size(); ++i)
		{
			if (board[0][i] == '#' || board[1][i] == '#')
			{
				return false;
			}
		}
		return true;
	}
	string judge(vector <string> board)
	{
		int db = 0;
		int innerdb = 0;
		int manipulations = 0;
		bool begin = true;
		bool nyert = false;
		bool also = false;
		if (allempty(board))
		{
			nyert = board[0].size() % 2;
		}
		else
		{
			int x = 0;
			for(unsigned i = 0; i<board[0].size(); ++i)
			{
				if ( board[0][i] == '.' && board[1][i] == '.')
				{
					++x;
				}
				else
				{
					if (board[0][i] == '#')
					{
						if (begin)
						{
							if (x>=2)
							{
								manipulations++;
							}
							db += x;
							innerdb -= x;
						}
						else
						{
							db += x;
							if (!also && x>0)
							{
								--db;
							}
							innerdb -= x;
						}
						begin = false;
						also = true;
						x = 0;
					}
					else
					{
						if (begin)
						{
							if (x>=2)
							{
								manipulations++;
							}
							db += x;
						}
						else
						{
							db += x;
							if (also && x>0)
							{
								--db;
							}
						}
						begin = false;
						also = false;
						x = 0;
					}
				}
			}
			innerdb += db;
			db += x;
			if (x>=2)
			{
				++manipulations;
			}
		}

		nyert = ( (manipulations == 1) || ((manipulations == 0) && (db % 2)) || ((manipulations == 2) && ( (innerdb + 1000000)% 2)));

		if (nyert)
		{
			return string("Snuke");
		}
		else
		{
			return string("Sothe");
		}
	}
};
