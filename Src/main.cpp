#include "AudioManager.h"
#include "Scene1.h"

/*
3 objetos básicos:
Buffer. Almacena el sonido. Puede ser utilizado por diferentes sources.
Sources. Punto del espacio que emite snidos. Se pueden modificar propiedades. (Posicion y velocidad)
Listener. Posición, orientación y velocidad del oyente. Se pueden modificar propiedades.

Unidades-

Sources.
alSourcefv(). Una única función para modificar propiedades -

Contexto. Estado de OpenAL (escena). Se pueden tener varios e ir intercambiando.-

El código está con Alut. Elige la mejor configuracion. Se puede ir a mas bajo nivel con AL

Hay cosas con AL que con un coñazo en las diapos

Si queremos lanzar error diapos.
alGen crea tanto buffers como sources

Las llamadas a al() siguen un convenio.
*/

//
//class Ejercicio2 {
//public:
//	Ejercicio2()
//	{

//
//		//Creación source
//		ALuint *Source;
//		alGenSources(3, Source);	//Número de sources, puntero a ellas
//
//		ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };
//		ALfloat SourceVel[] = { 0.0f, 0.0f, 0.1f };
//
//		//Enganchar buffer a source
//		alSourcei(Source[0], AL_BUFFER, Buffer[0]);
//
//		//Propiedades del source
//		alSourcefv(Source[0], AL_POSITION, SourcePos);
//		alSourcefv(Source, AL_VELOCITY, SourceVel);
//		alSourcef(Source, AL_PITCH, 1.0); // frec de reproduccion
//		alSourcef(Source, AL_GAIN, 1.0); // ganancia de la fuente
//		alSourcei(Source, AL_LOOPING, true); // para repr. ciclica
//
//											 /*hAY QUE HACER UN BUCLE DE JUEGO*/
//		ALubyte c = ' ';
//		ALfloat pitch = 1.0;
//		while (c != 'q') {
//			c = _getche();
//			switch (c) {
//				// Pulsando 'p' empiza la reproduccion del sample
//			case 'p': alSourcePlay(Source); break;
//				// Con 's' se para la reproduccion
//			case 's': alSourceStop(Source); break;
//				// Con 'h' se pausa. Con 'p' se reinicia
//			case 'h': alSourcePause(Source); break;
//			case 'e':
//				pitch += 0.1;
//				if (pitch > 4)
//					pitch = 4;
//
//				alSourcef(Source, AL_PITCH, pitch); // frec de reproduccion
//				break;
//			case 'd':
//				pitch -= 0.1;
//				if (pitch < 0)
//					pitch = 0;
//				alSourcef(Source, AL_PITCH, pitch); // frec de reproduccion
//				break;
//
//			};
//		}
//
//		// una forma de inventarse un renderizado
//		//ALint time = 0, elapse = 0;
//		//while (!_kbhit()) {
//		//	elapse += clock() - time;
//		//	time += elapse;
//		//	//printf("Elapse: %i time: %i", elapse, time); //salida
//		//	if (elapse > 50) {
//		//		// reseteamos
//		//		elapse = 0;
//		//		// SourcePos[0] += SourceVel[0];
//		//		// SourcePos[1] += SourceVel[1]
//		//		//Es necesario siempre hacer esto para mover un sonido
//		//		SourcePos[2] += SourceVel[2]; // este es el que cambia, la Z
//		//									  // actualizamos la posicion del source
//		//		alSourcefv(Source, AL_POSITION, SourcePos);
//		//	}
//		//}
//
//		//alutSleep(3);//Pausa para escuchar
//
//		//Liberacíon de recursos y salida
//		alDeleteBuffers(1, &Buffer);
//		alDeleteSources(1, &Source);
//
//	}

//};


int main() {

	AudioManager * audioManager;
	audioManager = AudioManager::GetInstance();
	
	Scene1* scene = new Scene1();
	scene->Init();
	scene->Loop();
	delete scene;

	audioManager->ResetInstance();

	return EXIT_SUCCESS;
}





