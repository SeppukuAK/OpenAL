#include "Scene1.h"



Scene1::Scene1() : Scene()
{
	
}


Scene1::~Scene1()
{
}

void Scene1::Init()
{
	AudioManager * audioManager = AudioManager::GetInstance();
	//Carga de recursos
	std::string audioPath[] = { "../../Media/motores/1.wav" };
	audioManager->LoadAudio(audioPath[0]);
	audioManager->ShowAudioInfo(audioPath[0]);

	std::vector<AudioSource*> audioSourceActors;

	////Creación listener
	//ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };
	//AudioManager::GetInstance()->SetListenerPos(ListenerPos);

	//ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };
	//AudioManager::GetInstance()->SetListenerVel(ListenerVel);

	//ALfloat ListenerOri[] = { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0 }; 	// Orientacion, mirando a la pantalla (los primeros 3 elementos son "at", los otros "up"). Todos los valores deben ser 1 o -1																//							----- at ----- ----- up ----
	//AudioManager::GetInstance()->SetListenerOri(ListenerOri);

	//Sources
	AudioSource* audioSource = new AudioSource();
	audioSource->SetAudioClip(audioManager->GetBuffer(audioPath[0]));	//Asocia buffer a source

																		//ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };
																		//ALfloat SourceVel[] = { 0.0f, 0.0f, 0.1f };


}

void Scene1::Loop()
{
	ALubyte c = ' ';
	ALfloat pitch = 1.0;
	while (c != 'q') {
		c = _getche();
		switch (c) {
			// Pulsando 'p' empiza la reproduccion del sample
		case 'p': audioSource->Play(); break;
			// Con 's' se para la reproduccion
		case 's': audioSource->Stop(); break;
			// Con 'h' se pausa. Con 'p' se reinicia
		case 'h':audioSource->Pause(); break;
		case 'e':
			pitch += 0.1;
			if (pitch > 4)
				pitch = 4;

			audioSource->SetSourcePitch(pitch); break;
		case 'd':
			pitch -= 0.1;
			if (pitch < 0)
				pitch = 0;
			audioSource->SetSourcePitch(pitch); break;

		};
	}
}
