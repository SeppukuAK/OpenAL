#ifndef __Scene_h_
#define __Scene_h_

class Scene
{
public:
	virtual void Init() = 0;
	virtual void Loop() = 0;
};
#endif // #ifndef _Scene_h_