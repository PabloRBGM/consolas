#pragma once
//no vale herencia de comandos porque hacer muchos news y deletes es malo, y para que funcione la herencia dinamica la cola 
//tendria que ser de punteros que implica hacer new desde la hebra de logica y cuando se lee un comando hacer un delete desde la hebra de render
//union se usa para programacion de sistemas. Nos sirve porque solo vamos a usar una de todos los tipos, entonces queremos que 
//ocupe en memoria como la estructura mas grande, no la suma de todos ellos.
//lo que est� dentro de una union, no puede tener constructor

#include "RenderCommand.h"
#include <atomic>
#include <thread>
#include <condition_variable>
#include <mutex>

template <typename T>
class ConcurrentQueue;

class RenderThread {
public:
	static void Start();
	static void Stop();
	static void addCommand(const RenderCommand& command);
	static unsigned int getFrames() { return _frames; }
	static void IncreaseFrames();
	static std::condition_variable _cv;
	static std::mutex _mutex;
	static std::unique_lock<std::mutex> _lock;
	static const short maxQueue;

private:
	static std::thread _renderThread;
	static std::atomic<bool> _exit;
	static std::atomic<unsigned int> _frames;
	static ConcurrentQueue<RenderCommand> _q;


	static void run();
};

//Renderer::Clear(uint32_t color);
//Renderer::DrawImage(Image*, x1...);

