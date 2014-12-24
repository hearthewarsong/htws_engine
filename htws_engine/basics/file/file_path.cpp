/*
 * file_path.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: hearthewarsong
 */

#include "../basics_all.h"

FilePath::~FilePath()
{
}

FilePath::FilePath(const char* file_path) :path(file_path)
{
}

OWNERSHIP FILE* FilePath::FOpen(const char* mode) const
{
	return fopen(path.c_str(),mode);
}
