#include "AudioManager.h"
#include <stdlib.h>
#include <al.h>
#include <alut.h>

using namespace std;

#pragma region Singleton  

/* Null, because instance will be initialized on demand. */
AudioManager* AudioManager::instance = 0;

AudioManager* AudioManager::GetInstance()
{
	if (instance == 0)
		instance = new AudioManager();

	return instance;
}

void AudioManager::ResetInstance() {
	delete instance;
	instance = nullptr;
}

#pragma endregion Singleton


AudioManager::AudioManager()
{
	Init();
}

AudioManager::~AudioManager()
{
	Destroy();
}

void AudioManager::Init()
{
	//Inicialización OpenAL
	alutInit(0, NULL);	//Alut 
	alGetError(); //limpiamos el bit de error
}

void AudioManager::Destroy()
{
	std::map<std::string, ALuint>::iterator it = soundFiles.begin();

	while (it != soundFiles.end())
	{
		alDeleteBuffers(1, &it->second); //Se borran los buffer
		it++;
	}

	alutExit();
}

void AudioManager::LoadAudio(std::string path)
{
	//Creación buffer
	ALuint Buffer = alutCreateBufferFromFile(path.c_str());
	if (alGetError() != AL_NO_ERROR) exit(-1);

	//Inserta
	soundFiles[path] = Buffer;
}

void AudioManager::ShowAudioInfo(std::string path)
{
	//Si existe la clave
	if (soundFiles.find(path) != soundFiles.end())
	{
		//Información sobre el Wav
		ALint frecuencia, bitsRes, canales, tamanio;
		alGetBufferi(soundFiles[path], AL_FREQUENCY, &frecuencia);
		alGetBufferi(soundFiles[path], AL_BITS, &bitsRes);
		alGetBufferi(soundFiles[path], AL_CHANNELS, &canales);
		alGetBufferi(soundFiles[path], AL_SIZE, &tamanio);
		printf("\n\nFormato del wav:\n");
		printf("Frec: %i\n", frecuencia);
		printf("BitsRes: %i\n", bitsRes);
		printf("Canales: %i\n", canales);
		printf("Tamanio: %i\n", tamanio);
	}
}

void AudioManager::SetListenerPos(ALfloat * listenerPos)
{
	alListenerfv(AL_POSITION, listenerPos);
}

void AudioManager::SetListenerVel(ALfloat * listenerPos)
{
	alListenerfv(AL_POSITION, listenerPos);
}

void AudioManager::SetListenerOri(ALfloat * listenerPos)
{
	alListenerfv(AL_POSITION, listenerPos);
}

 ALuint AudioManager::GetBuffer(std::string path)
{
	 //Si existe la clave
	 if (soundFiles.find(path) != soundFiles.end())
	 {
		 return soundFiles[path];
	 }
	 //TODO: LANZAR ERROR
}


