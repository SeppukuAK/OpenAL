#include <stdlib.h>
#include <al.h>
#include <alut.h>
#include <alc.h>

/*
3 objetos básicos:
Buffer. Almacena el sonido. Puede ser utilizado por diferentes sources.
Sources. Punto del espacio que emite snidos. Se pueden modificar propiedades. (Posicion y velocidad)
Listener. Posición, orientación y velocidad del oyente. Se pueden modificar propiedades.

Unidades-

Sources.
alSourcefv(). Una única función para modificar propiedades -

Contexto. Estado de OpenAL (escena). Se pueden tener varios e ir intercambiando.-

El código está con Alut. Elige la mejor configuracion. S epuede ir a mas bajo nivel con AL

*/

int main() {
	//Inicialización OpenAL
	alutInit(0, NULL);	//Alut 
	alGetError(); //limpiamos el bit de error

	//Creación buffer
	ALuint Buffer = alutCreateBufferFromFile("../../Media/batalla/Battle.wav");
	if (alGetError() != AL_NO_ERROR) exit(-1);

	//Creación source
	ALuint Source;
	alGenSources(1, &Source);

	//Enganchar buffer a source
	alSourcei(Source, AL_BUFFER, Buffer);

	//Reproduccion
	alSourcePlay(Source);

	//Pausa para escuchar
	alutSleep(3);

	//Liberacíon de recursos y salida
	alutExit();
	return EXIT_SUCCESS;
}