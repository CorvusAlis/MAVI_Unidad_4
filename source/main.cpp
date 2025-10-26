#ifndef NDEBUG
#include <vld.h>
#endif

#include "raylib.h"
#include "fantasma.h"

int main(void)
{

    InitWindow(1024, 768, "Fantasmas!");
    SetTargetFPS(60);

    //para instrucciones
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    const char* instrucciones = "Usa las flechas para mover al fantasma activo - Usa la barra espaciadora para cambiar el fantasma activo";
    int fontSize = 19;
    int anchoTexto = MeasureText(instrucciones, fontSize);

    //Fantasma::Fantasma(const string rutaTextura, Vector2 pos, float escala, float rotacion, float vel, Color color, bool activo)
    //crear objeto fantasma purpura en la esquina superior izquierda
    Fantasma fanti1("assets/fantasma.png", { 150, 200 }, 3.0f, 0.0f, 3.0f, DARKPURPLE, true);
    Fantasma fanti2("assets/fantasma.png", { 800, 600 }, 3.0f, 0.0f, 3.0f, GRAY, false);

    while (!WindowShouldClose())
    {
        fanti1.ActualizarPos(); //controla movimiento por teclado con flechas
        fanti2.ActualizarPos();

        BeginDrawing();
            
            fanti1.MostrarInfo({ 20,20 });
            fanti2.MostrarInfo({ (float)GetScreenWidth() - 250, 20 });

            ClearBackground(RAYWHITE);
            fanti1.Dibujar();
            fanti2.Dibujar();

            //instrucciones
            DrawText(instrucciones, (screenWidth - anchoTexto) / 2, screenHeight - 40, fontSize, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

