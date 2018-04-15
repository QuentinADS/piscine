#include "grman/grman.h"
#include <iostream>
#include <allegro.h>

#include "graph.h"

void lancer(std::string nom)
{
    grman::set_pictures_path("pics");

    Graph g;
    g.make_example(nom);

    while(!key[KEY_SPACE])
    {

        g.update();
        grman::mettre_a_jour();
    }
}

int choix_graph()
{
    int i;

    clear_bitmap(screen);
    BITMAP* buffer=NULL;
    buffer=create_bitmap(800,600);

    while(!key[KEY_SPACE])
    {
        grman::show_picture(buffer, "choix.bmp", 0, 0, 0);
        if(mouse_b&1 && mouse_x>50 && mouse_y>150 && mouse_x<200 && mouse_y<500)
        {
            rect(buffer, 50, 150, 200, 500, 255);
            rest(100);
            i=1;
        }
        if(mouse_b&1 && mouse_x>336 && mouse_y>195+75 && mouse_x<511 && mouse_y<237+75)
        {

            rest(100);

        }
        if(mouse_b&1 && mouse_x>336 && mouse_y>336+75 && mouse_x<511 && mouse_y<377+75)
        {
            rest(100);

        }

    }
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    return i;
}

void afficher_choix()
{

    clear_bitmap(screen);
    BITMAP* buffer=NULL;
    buffer=create_bitmap(800,600);


    while(!key[KEY_SPACE])
    {
        grman::show_picture(buffer, "choix.bmp", 0, 0, 0);
        if(mouse_x>50 && mouse_y>150 && mouse_x<200 && mouse_y<500)
        {
            rect(buffer, 15, 150, 200, 500, 255);

            if(mouse_b&1)
                lancer("GrapheMarais");
        }

        if(mouse_x>230 && mouse_y>150 && mouse_x<500 && mouse_y<500)
        {
            rect(buffer, 230, 150, 500, 500, 255);

            if(mouse_b&1)
                lancer("GrapheOcean");
        }

        if(mouse_x>505 && mouse_y>150 && mouse_x<790 && mouse_y<500)
        {
            rect(buffer, 505, 150, 790, 500, 255);

            if(mouse_b&1)
                lancer("GrapheSavanne");
        }

        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    }

}

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");
    BITMAP* buffer=NULL;
    buffer=create_bitmap(800,600);


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {
        grman::show_picture(buffer, "menu.bmp", 0, 0,0);
        if((mouse_x<SCREEN_W-350)&&(mouse_x>SCREEN_W-450))
            if((mouse_y<SCREEN_H-50)&&(mouse_y>SCREEN_H-100))
            {
                rect(buffer, 350, 505, 460, 545, 0);
                if(mouse_b&1)
                {
                    afficher_choix();

                }

            }


        blit(buffer, screen, 0, 0, 0, 0, grman::page->w, grman::page->h);
    }


    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();
