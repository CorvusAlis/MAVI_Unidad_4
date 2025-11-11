#ifndef NDEBUG
#include <vld.h>
#endif

#include "raylib.h"
#include "grim.h"

int main(void)
{

    InitWindow(1024, 768, "Jumping Grim");
    SetTargetFPS(60);

    //Grim::Grim(const string rutaTextura, Vector2 pos, float escala, float vel, bool mostrando)
 
    Grim grim("assets/grim.png", { 50, 500 }, 0.5f, 10.0f, true);


    while (!WindowShouldClose())
    {
        grim.ActualizarPos();   //control del movimiento en cada frame

        BeginDrawing();
            
            grim.MostrarInfo({ 20,20 });    //muestra las coordenadas actuales de Grim o se ocultan, con la tecla M

            ClearBackground(RAYWHITE);
            grim.Dibujar();     //render del sprite

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

