#pragma once
//no vale herencia de comandos porque hacer muchos news y deletes es malo, y para que funcione la herencia dinamica la cola 
//tendria que ser de punteros que implica hacer new desde la hebra de logica y cuando se lee un comando hacer un delete desde la hebra de render
//union se usa para programacion de sistemas. Nos sirve porque solo vamos a usar una de todos los tipos, entonces queremos que 
//ocupe en memoria como la estructura mas grande, no la suma de todos ellos.
//lo que est� dentro de una union, no puede tener constructor

#include "RenderCommand.h"
#include <atomic>
#include <thread>
#include "../atomicops.h"
#include "../readerwriterqueue.h"


class RenderThread {
public:
	void Start();
	void Stop();
	void addCommand(RenderCommand* command);
private:
	std::thread _renderThread;
	std::atomic<bool> _exit;
	std::atomic<unsigned int> _frames;
	moodycamel::ReaderWriterQueue<RenderCommand*> _q;
	void run();
};

//Renderer::Clear(uint32_t color);
//Renderer::DrawImage(Image*, x1...);

