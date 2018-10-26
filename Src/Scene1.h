#ifndef __Scene1_h_
#define __Scene1_h_

#include "Scene.h"
#include "AudioSource.h"

class Scene1 : Scene
{
public:
	Scene1();
	~Scene1();

	void Init();
	void Loop();

protected:
	AudioSource * audioSource;
};
#endif // #ifndef _Scene1_h_

