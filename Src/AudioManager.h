#ifndef __AudioManager_h_
#define __AudioManager_h_

#include <map>
#include "al.h"
class AudioManager
{
#pragma region Singleton  
private:
	/* Here will be the instance stored. */
	static AudioManager *instance;

public:
	/* Static access method. */
	static AudioManager * GetInstance();
	static void ResetInstance();

#pragma endregion Singleton

public:
	AudioManager();
	~AudioManager();

	void LoadAudio(std::string path);
	void ShowAudioInfo(std::string path);

	void SetListenerPos(ALfloat * listenerPos);
	void SetListenerVel(ALfloat * listenerVel);
	void SetListenerOri(ALfloat * listenerOri);

	ALuint GetBuffer(std::string path);

private:
	void Init();
	void Destroy();

	std::map<std::string, ALuint> soundFiles;
	
};
#endif // #ifndef __AudioManager_h_

