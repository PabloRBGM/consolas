#pragma once

#include <stdio.h>
#include <cstdint>

/*
	Clase para representar los mapas de esta practica.

	El mapa tiene 2 planos de 64*64 (se puede intidcar
	otro tama�o al construirlo)
	El primer plano con informacion del nivel
	
		* un tile con valor i se pinta en 2*i -1
	el segundo plano con la informacion del player, 
	solo quedarse con el valor entre 19 y 22 inclusives
		
		* 19 player mira norte, 20 este, 21, sur, 22 oeste
*/
class Map {
public:

	// Crea un mapa vacio con las caracteristicas de la practica
	Map();

	// Destructora
	~Map();

	// Carga el mapa de archivo
	bool load(FILE* file, bool bigEndian);

	// Getters
	int getSize() const;
	int getWidth() const;
	int getHeight() const;
	const char* getName() const;
	uint16_t getPlayerSpawnPoint() const;
	uint16_t getPlayerOrientation() const;

	// Devuelve un tile del primer plano
	uint16_t getTile(int i) const;

	// Metodos sobre la informacion del mapa
	bool isTransitable(int x, int y) const;
	

private:

	// Ancho del mapa
	const int MAPWIDTH = 64;

	// Alto del mapa
	const int MAPHEIGHT = 64;

	// Tama�o total del mapa
	const int MAPSIZE = MAPWIDTH * MAPHEIGHT;

	// Longitud del nombre
	const int MAPNAMESIZE = 16;

	// Informacion del mapa
	uint16_t* _mapInfo = nullptr;

	// Nombre del mapa
	char* _name = nullptr;

	// Posicion y orientacion inicial del jugador
	uint16_t* _playerStart = nullptr;

	// Libera la memoria
	void free();
};