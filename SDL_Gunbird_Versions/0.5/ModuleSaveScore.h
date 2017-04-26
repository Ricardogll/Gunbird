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

	int saveScore[12];
	uint saveCharacter[12];
};

#endif //__ModuleSaveScore_H__