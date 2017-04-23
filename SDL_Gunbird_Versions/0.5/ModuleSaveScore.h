#ifndef __ModuleSaveScore_H__
#define __ModuleSaveScore_H__

#include "Module.h"

class ModuleSaveScore : public Module
{
public:
	ModuleSaveScore();
	~ModuleSaveScore();

	bool Init();
	update_status Update();
	bool CleanUp();

public:

	int saveScore[10];
	uint saveCharacter[10];
};

#endif //__ModuleSaveScore_H__