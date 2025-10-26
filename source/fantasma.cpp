#include "Fantasma.h"

using namespace std;

//para mostrar el nombre del color segun sus valores RGB
const char* NombreColor(Color c) {
    if (c.r == 112 && c.g == 31 && c.b == 126) return "Violeta";
    if (c.r == 130 && c.g == 130 && c.b == 130) return "Gris";

    return "Color personalizado";
}

//crear un fantasma
Fantasma::Fantasma(const string rutaTextura, Vector2 pos, float escala, float rotacion, float vel, Color color, bool activo)
    : posicion(pos), escala(escala), rotacion(rotacion), velocidad(vel), color(color), activo(activo)
{
    textura = LoadTexture(rutaTextura.c_str());
    SetTextureFilter(textura, TEXTURE_FILTER_POINT);    //este filtro es mejor para pixel art
    //SetTextureFilter(textura, TEXTURE_FILTER_BILINEAR); //este filtro hace que se vea borroso al ser pixel art
}

//destruir fantasma y liberar recursos
Fantasma::~Fantasma()
{
    //se usa cuando se cierra la pantalla o se sale del bloque donde se usa el objeto
    UnloadTexture(textura);
}

//muestra el fantasma en pantalla 
void Fantasma::Dibujar()
{   
    //controlo el color segun se pueda mover o no
    Color colorF = activo ? color : GRAY;

    if (!activo) escala = 2.0;
    else escala = 3.0;

    //DrawTextureEx(Texture2D textura, Vector2D posicion, float rotacion, float escala, Color color)
    DrawTextureEx(textura, posicion, rotacion, escala, colorF);
}

void Fantasma::Mover(float x, float y)
{
    posicion.x += x;
    posicion.y += y;
}

void Fantasma::ActualizarPos() {

    if (IsKeyPressed(KEY_SPACE)) Swap();
    if (!activo) return; //si no esta activo, no se mueve (no pasa a la siguiente parte del codigo)

    if (IsKeyDown(KEY_RIGHT)) Mover(velocidad, 0);
    if (IsKeyDown(KEY_LEFT))  Mover(-velocidad, 0);
    if (IsKeyDown(KEY_UP))    Mover(0, -velocidad);
    if (IsKeyDown(KEY_DOWN))  Mover(0, velocidad);

}

void Fantasma::SetPosicion(Vector2 pos)
{
    posicion = pos;
}

void Fantasma::Swap() {
        //controla si el fantasma esta activo o no - ESTO FUNCIONA PARA DOS FANTASMAS - control con bool
        //VER COMO HACER SI SE TIENEN MAS FANTASMAS - quizas un vector que tenga el estado de todos los fantasmas
        activo = !activo;

        if (activo)
        {
            color = DARKPURPLE;
            escala = 3.0;
        }
        else
        {
            color = GRAY;
            escala = 2.0;
        }
}

void Fantasma::MostrarInfo(Vector2 posicionInfo) {
    DrawText(TextFormat("Posicion: (%.0f, %.0f)", posicion.x, posicion.y),
        posicionInfo.x, posicionInfo.y, 20, DARKGRAY);

    DrawText(TextFormat("Escala: %.2f", escala),
        posicionInfo.x, posicionInfo.y + 25, 20, DARKGRAY);

    DrawText(TextFormat("Color: %s", NombreColor(color)), posicionInfo.x, posicionInfo.y + 50, 20, DARKGRAY);
}

Vector2 Fantasma::GetPosicion() const
{
    return posicion;
}