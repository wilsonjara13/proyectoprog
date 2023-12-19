
#include "tigr/tigr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define ncasilla 36

void red()
{
    printf("\033[1;31m");
}

void green()
{
    printf("\033[1;32m");
}

void yellow()
{
    printf("\033[1;33m");
}

void reset()
{
    printf("\033[0m");
}

void salto()
{
    printf("\n");
}

void clear()
{
    system("clear");
}

void moverderechaventana()
{
    system("xdotool key Super+Right");
}

void redimensionar()
{

    system("xdotool key Alt+F8");
    for (int i = 0; i < 50; i++)
    {
        system("xdotool key Left");
    }
    system("xdotool key Return");
    system("xdotool key Alt+Tab");
}

void cambiarventana()
{
    system("xdotool key Alt+Tab");
}

typedef struct
{
    int x;
    int y;

} Grafica;

typedef struct
{
    int x;
    int y;

} Casa;

typedef struct
{
    char nombre[50];
    int precio;
    char grupo[20];
    int propietario;
    bool estoy;
    bool estoy2;
    Grafica eje;
    Casa axis;
} Casilla;

Casilla casillas[ncasilla] = {
    {"Salida", 200, "Salida", 5, true, true, {900, 920}, {900, 880}},                  // 0
    {"Estacion de tren", 200, "Estacion", 0, false, false, {810, 920}, {810, 880}},    // 1
    {"Tarifa", 150, "Marron", 0, false, false, {715, 920}, {715, 880}},                // 2
    {"Osuna", 250, "Marron", 0, false, false, {620, 920}, {620, 880}},                 // 3
    {"Compañia electrica1", 200, "Estacion", 0, false, false, {525, 920}, {525, 880}}, // 4
    {"Oliva", 300, "Verde", 0, false, false, {430, 920}, {430, 880}},                  // 5
    {"Bacarot", 90, "Verde", 0, false, false, {335, 920}, {335, 880}},                 // 6
    {"Villareal", 150, "Verde", 0, false, false, {240, 920}, {240, 880}},              // 7
    {"Impuesto", 100, "Impuesto", 20, false, false, {145, 920}, {145, 880}},           // 8
    {"Carcel", 0, "Carcel", 10, false, false, {50, 920}, {100, 880}},                  // 9
    {"Cofre", 0, "Cofre", 15, false, false, {50, 800}, {90, 865}},                     // 10
    {"Compañia de agua1", 200, "Estacion", 0, false, false, {50, 700}, {90, 710}},     // 11
    {"Logroño", 300, "Amarillo", 0, false, false, {50, 600}, {90, 630}},               // 12
    {"Castroviejo", 200, "Amarillo", 0, false, false, {50, 510}, {90, 535}},           // 13
    {"Enciso", 100, "Amarillo", 0, false, false, {50, 420}, {90, 440}},                // 14
    {"Impuesto", 200, "Impuesto", 20, false, false, {50, 315}, {90, 315}},             // 15
    {"Estacion de tren2", 200, "Estacion", 0, false, false, {50, 210}, {90, 230}},     // 16
    {"Cofre", 0, "Cofre", 15, false, false, {50, 120}, {90, 120}},                     // 17
    {"Carcel", 0, "Carcel", 10, false, false, {50, 10}, {90, 10}},                     // 18
    {"Gijon", 150, "Naranja", 0, false, false, {145, 10}, {145, 100}},                 // 19
    {"Oviedo", 250, "Naranja", 0, false, false, {240, 10}, {240, 100}},                // 20
    {"Tanes", 100, "Naranja", 0, false, false, {335, 10}, {335, 100}},                 // 21
    {"Compañia electrica2", 200, "Estacion", 0, false, false, {430, 10}, {430, 100}},  // 22
    {"Impuesto", 200, "Impuesto", 20, false, false, {525, 10}, {525, 100}},            // 23
    {"Villaviciosa", 150, "Naranja", 0, false, false, {620, 10}, {620, 100}},          // 24
    {"Cofre", 0, "Cofre", 15, false, false, {715, 10}, {715, 100}},                    // 25
    {"Compañia de agua2", 200, "Estacion", 0, false, false, {810, 10}, {810, 100}},    // 26
    {"Carcel", 0, "Carcel", 10, false, false, {930, 10}},                              // 27
    {"Girona", 200, "Rosa", 0, false, false, {930, 120}, {860, 135}},                  // 28
    {"Tarragona", 300, "Rosa", 0, false, false, {930, 220}, {860, 230}},               // 29
    {"Estacion de tren3", 200, "Estacion", 0, false, false, {930, 315}, {860, 315}},  // 30
    {"Impuesto", 200, "Impuesto", 20, false, false, {930, 410}, {860, 440}},            // 31
    {"Reus", 200, "Rosa", 0, false, false, {930, 510}, {860, 535}},                    // 32
    {"Mataro", 150, "Rosa", 0, false, false, {930, 610}, {860, 630}},                  // 33
    {"Cofre", 0, "Cofre", 15, false, false, {930, 700}, {860, 710}},                   // 34
    {"Impuesto", 200, "Impuesto", 20, false, false, {930, 800}, {860, 800}},            // 35

};

typedef struct
{
    int posicion;
    char ficha;
    int monedero;
    bool carcel;
} Jugador;

Jugador jugador1 = {0, '*', 3000, false};
Jugador jugador2 = {0, '!', 50, false};

void imp_menu(int jugador)
{
    yellow();
    printf("\n\n----Menu J%d----\n", jugador);
    reset();
    printf("1) Tirar dado\n");
    printf("2) Terminar Juego\n");
}

int tirarDado()
{
    return rand() % 6 + 1;
}

int cambiarturno(int *jugadoractual)
{
    if (*jugadoractual == 1) // Cambia turno a J2
    {
        *jugadoractual = 2;
    }
    else // Cambia turno a J1
    {
        *jugadoractual = 1;
    }
}

int comprar(int indice, int turno)
{
    char check;

    if (turno == 1)
    {
        if (jugador1.posicion == indice)
        {
            if (casillas[indice].propietario == 0 && casillas->propietario != 2)
            {
                do
                {
                    printf("¿Desea comprar la propiedad por %d€? (s/n): ", casillas[indice].precio);
                    scanf(" %c", &check);
                } while (check != 's' && check != 'S' && check != 'n' && check != 'N');

                if (check == 's' || check == 'S')
                {
                    if (jugador1.monedero >= casillas[indice].precio)
                    {
                        green();
                        printf("¡HA COMPRADO LA PROPIEDAD!\n");
                        reset();

                        salto();
                        printf("\t[!]TURNO DEL JUGADOR 2\n");

                        sleep(2);

                        jugador1.monedero -= casillas[indice].precio;
                        casillas[indice].propietario = 1;
                    }
                    else
                    {
                        red();
                        printf("Estas pobre, haber estudiado");
                        reset();
                        salto();

                        sleep(2);
                    }
                }
            }
            else
            {
                printf("NO PUEDES COMPRAR UNA PROPIEDAD QUE PERTENECE A OTRO JUGADOR\n");
                sleep(2);
            }
        }
    }
    else
    {
        if (jugador2.posicion == indice)
        {
            if (casillas[indice].propietario == 0 && casillas->propietario != 1)
            {
                do
                {
                    printf("¿Desea comprar la propiedad por %d€? (s/n): ", casillas[indice].precio);
                    scanf(" %c", &check);
                } while (check != 's' && check != 'S' && check != 'n' && check != 'N');

                if (check == 's' || check == 'S')
                {
                    if (jugador2.monedero >= casillas[indice].precio)
                    {
                        green();
                        printf("¡HA COMPRADO LA PROPIEDAD!\n");
                        reset();

                        salto();
                        printf("\t[!]TURNO DEL JUGADOR 2\n");

                        sleep(2);

                        jugador2.monedero -= casillas[indice].precio;
                        casillas[indice].propietario = 2;
                    }
                    else
                    {
                        red();
                        printf("Estas pobre, haber estudiado");
                        reset();
                        salto();

                        sleep(2);
                    }
                }
            }
            else
            {
                printf("NO PUEDES COMPRAR UNA PROPIEDAD QUE PERTENECE A OTRO JUGADOR\n");
                sleep(2);
            }
        }
    }
}

int impuesto(int indice, int turno)
{
    if (turno == 1)
    {
        if (jugador1.posicion == indice)
        {
            yellow();
            printf("¡HAS CAIDO EN LA CASILLA DE IMPUESTOS!");
            reset();

            sleep(2);

            if (casillas[indice].propietario == 20)
            {
                int ale = rand() % 200;
                if (ale == 0)
                {
                    salto();
                    printf("¡Hacienda te perdona los impuestos!");
                    salto();
                    sleep(2);
                }
                else
                {
                    salto();
                    printf("¡Has pagado %d€ en impuestos!", ale);
                    salto();
                    jugador1.monedero -= ale;
                    sleep(2);
                }
            }
        }
    }
    else
    {
        if (jugador2.posicion == indice)
        {
            yellow();
            printf("¡HAS CAIDO EN LA CASILLA DE IMPUESTOS!");
            reset();
            salto();

            sleep(2);

            if (casillas[indice].propietario == 20)
            {
                int ale = rand() % 200;
                if (ale == 0)
                {
                    salto();
                    printf("¡Hacienda te perdona los impuestos!");
                    salto();
                    sleep(2);
                }
                else
                {
                    salto();
                    printf("¡Has pagado %d€ en impuestos!", ale);
                    salto();
                    jugador2.monedero -= ale;
                    sleep(2);
                }
            }
        }
    }
}

void carcel(int indice, int turno)
{
    if (turno == 1)
    {
        if (jugador1.posicion == indice)
        {
            yellow();
            printf("¡TE HA PILLADO LA POLICIA, VAS A LA CARCEL!");
            reset();
            salto();

            sleep(3);
            if (casillas[indice].propietario == 10)
            {
                jugador1.carcel = true;
            }
        }
    }
    else
    {
        if (jugador2.posicion == indice)
        {
            yellow();
            printf("¡TE HA PILLADO LA POLICIA, VAS A LA CARCEL!");
            reset();
            salto();

            sleep(2);

            if (casillas[indice].propietario == 10)
            {
                jugador2.carcel = true;
            }
        }
    }
}

int salircarcel(int *turno)
{
    if (*turno == 1)
    {
        jugador1.carcel = false;
    }
    else
    {
        jugador2.carcel = false;
    }
}

int cofre(int indice, int turno)
{
    if (turno == 1)
    {
        if (jugador1.posicion == indice)
        {
            yellow();
            printf("¡HAS CAIDO EN UNA CASILLA COFRE!");
            reset();
            salto();

            sleep(2);
            if (casillas[indice].propietario == 15)
            {
                int ale = rand() % 200;
                if (ale == 0)
                {
                    salto();
                    printf("¡Mala suerte!, te ha tocado 0€");
                    salto();
                    sleep(2);
                }
                else
                {
                    salto();
                    printf("¡Has encontrado %d€!", ale);
                    salto();
                    jugador1.monedero += ale;
                    sleep(2);
                }
            }
        }
    }
    else
    {
        if (jugador2.posicion == indice)
        {
            yellow();
            printf("¡HAS CAIDO EN UNA CASILLA COFRE!");
            reset();
            salto();

            sleep(2);

            if (casillas[indice].propietario == 15)
            {
                int ale = rand() % 200;
                if (ale == 0)
                {
                    salto();
                    printf("¡Mala suerte!, te ha tocado 0€");
                    salto();
                    sleep(2);
                }
                else
                {
                    salto();
                    printf("¡Has encontrado %d€!", ale);
                    salto();
                    jugador2.monedero += ale;
                    sleep(2);
                }
            }
        }
    }
}

void imprimirCasilla(int indice, int turno)
{
    casillas[jugador1.posicion].estoy = true;
    casillas[jugador2.posicion].estoy2 = true;

    printf("| C%d", indice);
    printf("<%s> <%d>", casillas[indice].nombre, casillas[indice].precio);

    if (casillas[indice].propietario == 1)
    {
        red();
        printf("<%d>", casillas[indice].propietario);
        reset();
    }

    if (casillas[indice].propietario == 2)
    {
        green();
        printf("<%d>", casillas[indice].propietario);
        reset();
    }

    if (casillas[indice].estoy == true)
    {
        red();
        printf("%c", jugador1.ficha);
        reset();
    }

    if (casillas[indice].estoy2 == true)
    {
        green();
        printf("%c", jugador2.ficha);
        reset();
    }
}

void infotablero()
{
    salto();

    printf("| ");
    for (int i = 0; i < ncasilla; i++)
    {

        printf("C%d", i);
        printf("<%s><%d> ", casillas[i].nombre, casillas[i].precio);

        if (casillas[i].propietario == 1)
        {
            red();
            printf("<%d> ", casillas[i].propietario);
            reset();
        }

        if (casillas[i].propietario == 2)
        {
            green();
            printf("<%d> ", casillas[i].propietario);
            reset();
        }

        if (casillas[i].estoy == true)
        {
            red();
            printf("*");
            reset();
        }

        if (casillas[i].estoy2 == true)
        {
            green();
            printf("!");
            reset();
        }

        printf("| ");
    }
    salto();
    printf("Saldo J1: %d", jugador1.monedero);

    salto();
    printf("Saldo J2: %d\n", jugador2.monedero);
}

int PagarAlquiler(int indice, int turno)
{
    if (turno == 1)
    {
        if (jugador1.posicion == indice && casillas[indice].propietario == 2)
        {
            int pagar = 0;

            yellow();
            pagar = casillas[indice].precio * 0.2;
            printf("¡Esta calle pertenece al jugador 2, tienes que pagar %d monedas de alquiler!", pagar);
            reset();
            salto();
            jugador1.monedero -= pagar;
            jugador2.monedero += pagar;

            sleep(2);
        }
    }
    else
    {
        if (jugador2.posicion == indice && casillas[indice].propietario == 1)
        {
            int pagar = 0;

            yellow();
            pagar = casillas[indice].precio * 0.2;
            printf("¡Esta calle pertenece al jugador 1, tienes que pagar %d monedas de alquiler!", pagar);
            reset();
            salto();
            jugador2.monedero -= pagar;
            jugador1.monedero += pagar;

            sleep(2);
        }
    }
}
int grafica(int turno)
{

    int x, y, x2, y2;
    // Crea una ventana de 800x600 píxeles
    Tigr *screen = tigrWindow(1920, 1080, "TIGR Image Loading", 0);

    // Carga una imagen desde un archivo
    Tigr *fondo;
    fondo = tigrLoadImage("./images/fondo.png");

    // Carga una imagen desde un archivo
    Tigr *ficha1;
    ficha1 = tigrLoadImage("./images/ficha.png");

    // Carga una imagen desde un archivo
    Tigr *ficha2;
    ficha2 = tigrLoadImage("./images/ficha2.png");

    if (!fondo)
    {
        tigrError(screen, "Error cargando el fondo.");
        return 1;
    }

    if (!ficha1)
    {
        tigrError(screen, "Error cargando la ficha1.");
        return 1;
    }

    if (!ficha2)
    {
        tigrError(screen, "Error cargando la ficha2.");
        return 1;
    }

    srand(time(NULL));
    sleep(2);

    // Borra la pantalla
    tigrClear(screen, tigrRGB(0, 0, 0));
    // Dibuja el fondo

    tigrBlitAlpha(screen, fondo, 0, 0, 0, 0, 1300, 1000, 1);
    tigrBlitAlpha(screen, ficha1, 900, 920, 0, 0, 50, 40, 1);
    tigrBlitAlpha(screen, ficha2, 945, 945, 0, 0, 40, 40, 1);

    // moverderechaventana();
    // sleep(2);
    // redimensionar();

    tigrUpdate(screen);

    tigrFree(fondo);
    tigrFree(ficha1);
    tigrFree(ficha2);
    tigrFree(screen);

    return 0;
}
int actualizar(int turno)
{

    int x, y, x2, y2, axisx, axisy;
    // Crea una ventana de 800x600 píxeles
    Tigr *screen = tigrWindow(1920, 1080, "TIGR Image Loading", 0);

    // Carga una imagen desde un archivo
    Tigr *fondo;
    fondo = tigrLoadImage("./images/fondo.png");

    if (!fondo)
    {
        tigrError(screen, "Error cargando el fondo.");
        return 1;
    }

    // Carga una imagen desde un archivo
    Tigr *ficha1;
    ficha1 = tigrLoadImage("./images/ficha.png");

    if (!ficha1)
    {
        tigrError(screen, "Error cargando la ficha1.");
        return 1;
    }

    // Carga una imagen desde un archivo
    Tigr *ficha2;
    ficha2 = tigrLoadImage("./images/ficha2.png");

    if (!ficha2)
    {
        tigrError(screen, "Error cargando la ficha2.");
        return 1;
    }

    // Carga una imagen desde un archivo
    Tigr *casa1;
    casa1 = tigrLoadImage("./house1.png");

    if (!casa1)
    {
        tigrError(screen, "Error cargando la casa1.");
        return 1;
    }

    // Carga una imagen desde un archivo
    Tigr *casa2;
    casa2 = tigrLoadImage("./house2.png");

    if (!casa2)
    {
        tigrError(screen, "Error cargando la casa2.");
        return 1;
    }

    srand(time(NULL));
    sleep(2);

    // Borra la pantalla
    tigrClear(screen, tigrRGB(0, 0, 0));
    // Dibuja el fondo
    tigrBlitAlpha(screen, fondo, 0, 0, 0, 0, 1300, 1000, 1);

    if (turno == 1)
    {
        for (int i = 0; i < ncasilla; i++)
        {
            if (jugador1.posicion == i)
            {
                x = casillas[i].eje.x;
                y = casillas[i].eje.y;
            }

            if (jugador2.posicion == i)
            {
                x2 = casillas[i].eje.x;
                y2 = casillas[i].eje.y;
            }

            if (casillas[i].propietario == 1)
            {
                axisx = casillas[i].axis.x;
                axisy = casillas[i].axis.y;

                tigrBlitAlpha(screen, casa1, axisx + 15, axisy, 0, 0, 50, 40, 1);
                tigrUpdate(screen);
            }

            if (casillas[i].propietario == 2)
            {
                axisx = casillas[i].axis.x;
                axisy = casillas[i].axis.y;

                tigrBlitAlpha(screen, casa2, axisx + 15, axisy, 0, 0, 50, 40, 1);
                tigrUpdate(screen);
            }
        }

        // Dibuja ficha1 y ficha2
        tigrBlitAlpha(screen, ficha1, x - 25, y, 0, 0, 50, 40, 1);
        tigrBlitAlpha(screen, ficha2, x2 + 25, y2 + 25, 0, 0, 40, 40, 1);

        tigrUpdate(screen);
    }
    else
    {
        for (int i = 0; i < ncasilla; i++)
        {
            if (jugador1.posicion == i)
            {
                x = casillas[i].eje.x;
                y = casillas[i].eje.y;
            }
            if (jugador2.posicion == i)
            {
                x2 = casillas[i].eje.x;
                y2 = casillas[i].eje.y;
            }
            if (casillas[i].propietario == 1)
            {
                axisx = casillas[i].axis.x;
                axisy = casillas[i].axis.y;

                tigrBlitAlpha(screen, casa1, axisx + 15, axisy, 0, 0, 50, 40, 1);
                tigrUpdate(screen);
            }
            if (casillas[i].propietario == 2)
            {
                axisx = casillas[i].axis.x;
                axisy = casillas[i].axis.y;

                tigrBlitAlpha(screen, casa2, axisx + 15, axisy, 0, 0, 50, 40, 1);
                tigrUpdate(screen);
            }
        }

        // Dibuja ficha1 y ficha2
        tigrBlitAlpha(screen, ficha1, x - 25, y, 0, 0, 50, 40, 1);
        tigrBlitAlpha(screen, ficha2, x2 + 25, y2 + 25, 0, 0, 40, 40, 1);

        tigrUpdate(screen);
    }

    // Borra la ventana o el bitmap
    tigrFree(fondo);
    tigrFree(ficha1);
    tigrFree(ficha2);
    tigrFree(screen);

    return 0;
}

int main()
{
    int menu, jugadoractual = 1;
    int empezar;

    srand(time(NULL));

    grafica(jugadoractual);
    sleep(2);
    cambiarventana();

    do
    {
        clear();

        // infotablero();

        for (int i = 0; i < ncasilla; i++)
        {
            casillas[i].estoy = false;
            casillas[i].estoy2 = false;
        }

        do
        {
            if (empezar == 0)
            {
                printf("Bienvenidos al juego del Monopoly\n");
                empezar++;
            }

            imp_menu(jugadoractual);

            printf("\nElegir una opción: ");
            scanf("%d", &menu);
            while (getchar() != '\n')
                ; // Limpia el buffer, sino se queda en bucle

            if (menu != 1 && menu != 2)
            {
                clear();
                yellow();
                printf("Introduzca una opción correcta\n");
                reset();
            }

        } while (menu != 1 && menu != 2);

        clear();

        switch (menu)
        {
        case 1:
            if (jugadoractual == 1) // Turno jugador 1
            {
                if (jugador1.carcel == true)
                {
                    // for (int i = 0; i < ncasilla; i += 1)
                    // {
                    //     imprimirCasilla(i, jugadoractual);
                    // }

                    salto();
                    salto();
                    red();
                    printf("[!] NO PUEDES TIRAR EN ESTE TURNO.\n");
                    reset();
                    sleep(2);
                    salircarcel(&jugadoractual);
                    cambiarturno(&jugadoractual);
                }
                else
                {

                    int resultadoDado = tirarDado();
                    printf("El J1 ha lanzado el dado: %d", resultadoDado);

                    // Mover al jugador
                    jugador1.posicion += resultadoDado;

                    // Vuelve a la casilla de salida si se pasa de la ultima
                    if (jugador1.posicion >= ncasilla)
                    {
                        jugador1.posicion -= ncasilla;
                        printf("\n¡Recibes 100€ por completar una vuelta al tablero!\n");
                        jugador1.monedero += 100;
                    }

                    // Imprimir la posición del jugador y su ficha
                    // for (int i = 0; i < ncasilla; i += 1)
                    // {
                    //     imprimirCasilla(i, jugadoractual);
                    // }

                    salto();
                    printf("Saldo J1: %d\n", jugador1.monedero);
                    printf("\n");
                    

                    for (int i = 0; i < ncasilla; i += 1)
                    {
                        if (casillas[i].propietario == 0)
                        {
                            comprar(i, jugadoractual);
                        }

                        if (casillas[i].propietario == 20)
                        {
                            impuesto(i, jugadoractual);
                        }

                        if (casillas[i].propietario == 15)
                        {
                            cofre(i, jugadoractual);
                        }
                        if (casillas[i].propietario == 10)
                        {
                            carcel(i, jugadoractual);
                        }
                        if (casillas[i].propietario == 2)
                        {
                            PagarAlquiler(i, jugadoractual);
                        }
                    }

                    sleep(1);
                    actualizar(jugadoractual);

                    sleep(2);
                    cambiarventana();

                    cambiarturno(&jugadoractual);
                }
            }
            else // Turno jugador 2
            {
                if (jugador2.carcel == true)
                {
                    // for (int i = 0; i < ncasilla; i += 1)
                    // {
                    //     imprimirCasilla(i, jugadoractual);
                    // }

                    salto();
                    salto();
                    red();
                    printf("[!] NO PUEDES TIRAR EN ESTE TURNO.\n");
                    reset();
                    sleep(2);
                    salircarcel(&jugadoractual);
                    cambiarturno(&jugadoractual);
                }
                else
                {
                    int resultadoDado = tirarDado();
                    printf("El J2 ha lanzado el dado: %d", resultadoDado);

                    // Mover al jugador
                    jugador2.posicion += resultadoDado;

                    // Vuelve a la casilla de salida si se pasa de la ultima
                    if (jugador2.posicion >= ncasilla)
                    {
                        jugador2.posicion -= ncasilla;
                        printf("\n¡Recibes 100€ por completar una vuelta al tablero!\n");
                        jugador2.monedero += 100;
                    }

                    // Imprimir la posición del jugador y su ficha
                    // for (int i = 0; i < ncasilla; i += 1)
                    // {
                    //     imprimirCasilla(i, jugadoractual);
                    // }

                    salto();
                    printf("Saldo J2: %d\n", jugador2.monedero);
                    printf("\n");

                    for (int i = 0; i < ncasilla; i += 1)
                    {
                        if (casillas[i].propietario == 0)
                        {
                            comprar(i, jugadoractual);
                        }

                        if (casillas[i].propietario == 20)
                        {
                            impuesto(i, jugadoractual);
                        }

                        if (casillas[i].propietario == 15)
                        {
                            cofre(i, jugadoractual);
                        }
                        if (casillas[i].propietario == 10)
                        {
                            carcel(i, jugadoractual);
                        }
                        if (casillas[i].propietario == 1)
                        {
                            PagarAlquiler(i, jugadoractual);
                        }
                    }
                    actualizar(jugadoractual);

                    sleep(2);
                    cambiarventana();

                    cambiarturno(&jugadoractual);
                }
            }

            break;

        default:
            printf("SE ACABO EL JUEGO\n\n");
            break;
        }
    } while (menu != 2);
}