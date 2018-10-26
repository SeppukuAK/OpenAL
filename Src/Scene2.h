#ifndef __Scene2_h_
#define __Scene2_h_

#include "Scene.h"
#include "AudioSource.h"

class Scene2 : Scene
{
public:
	Scene2();
	~Scene2();

	void Init();
	void Loop();

protected:
	AudioSource * audioSource;
};
#endif // #ifndef _Scene1_h_

