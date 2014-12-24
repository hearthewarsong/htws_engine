/*
 * file_path.h
 *
 *  Created on: Aug 24, 2014
 *      Author: hearthewarsong
 */

#ifndef FILE_PATH_H_
#define FILE_PATH_H_

class FilePath
{
	string path;
public:
	FilePath(const char* file_path);
	OWNERSHIP FILE* FOpen(const char* mode = "r") const;
	const string& GetPath() const { return path; }
	virtual ~FilePath();
};

#endif /* FILE_PATH_H_ */
