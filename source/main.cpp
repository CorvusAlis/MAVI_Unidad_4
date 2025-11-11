#ifndef NDEBUG
#include <vld.h>
#endif

#include "raylib.h"
#include "grim.h"

int main(void)
{
    //init de pantalla
    InitWindow(1024, 768, "Jumping Grim");
    SetTargetFPS(60);

    //init de audio
    InitAudioDevice();
 
    //color de fondo - bool para controlar cuando se clickea
    bool click = true;
    Color color1 = RAYWHITE;
    Color color2 = DARKPURPLE;
    Color colorBG = color1;
    Rectangle boton = { GetScreenWidth() - 150, 20, 120, 40};

    Grim grim("assets/images/grim.png", { 50, 500 }, 0.5f, 0.0f, 10.0f, true);

    while (!WindowShouldClose())
    {
        grim.ActualizarPos();   //control del movimiento en cada frame

        BeginDrawing();
            
            ClearBackground(colorBG);

            grim.MostrarInfo({ 20,20 });    //muestra las coordenadas actuales de Grim o se ocultan, con la tecla M
            grim.Dibujar();     //render del sprite

            //Boton para cambiar color de fondo (podria encapsularlo pero la logica es simple)
            DrawRectangleRec(boton, LIME);
            DrawText("Clickeame!", boton.x + 10, boton.y + 10, 20, BLACK);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Vector2 posMouse = GetMousePosition();
                //en vez de poner manualmente una zona de clickeo, comparo la posicion del mouse y el area del boton
                if (CheckCollisionPointRec(posMouse, boton)) {  //me fijo si coinciden - colision de toda la vida
                    click = !click;
                    colorBG = click ? color2 : color1;
                }
            }

        EndDrawing();
    }

    //cerrar sist de audio
    CloseAudioDevice();

    CloseWindow();

    return 0;
}

