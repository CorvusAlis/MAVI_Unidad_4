#pragma once
#include "raylib.h"
#include <string>

using namespace std;

class Fantasma {

private:
	Texture2D textura; //imagen que se va a mostrar
	Vector2 posicion;
	float escala;
	float rotacion;
	float velocidad;
	Color color;
	bool activo;

public:
	//constructor
	Fantasma(const string rutaTextura, Vector2 pos, float escala = 1.0f, float rotacion = 0.0f, float vel = 3.0f, Color color = WHITE, bool activo = true);
	//destructor - controla el UnloadTexture para liberar recursos
	~Fantasma();

	void Dibujar();	//render de la imagen
	void Mover(float x, float y);
	void ActualizarPos();
	void SetPosicion(Vector2 pos);
	void Swap();	//cambia el fantasma activo

	void MostrarInfo(Vector2 posicionInf);

	Vector2 GetPosicion() const; //devuelve la posicion actual de la imagen
};