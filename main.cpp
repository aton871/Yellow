#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "SystTour.h"
#include "Personnage.h"
#include "Tresorie.h"
#include "Mineur.h"
#include "Bandit.h"
#include "Ville.h"
#include "Evenements.h"

#include "MajTour.h"
#include "consoleDev.h"





int main (){



    // INITIALISATION DE L'ALEATOIRE

    srand(time(NULL));

    // INITIALISATION DES VARIABLES

    SystTour Tour("Charlie"); 

    int choixJoueur(1),tableau(0),affichage(42); 


// INITIALISATION DES OBJETS


    Ville Anzin("Anzin",5);



    Mineur Joueur(101,100,"Charlie",6,true);  

    //Comme c'est le Joueur, il a 1 points de vie en plus que tous les autres personnages, pour l'éviter de mourir bêtement dans un éboulement



    std::vector<Mineur> listeMineurs;
    std::vector<Bandit> listeBandits;

    listeMineurs.push_back(Joueur);

    Tresorie Tresor;
    Tresor+=20;

    Evenements CHAOS;   


    //PARTIE GRAPHIQUE

    //Création de la fenêtre graphique
    sf::RenderWindow window(sf::VideoMode(1000, 600,32), "Jaune la pepite!!"); //creation de la fenetre
    

    //Chargement de la police
    sf::Font font;
    if (!font.loadFromFile("west.ttf")) return EXIT_FAILURE;  // police



    //affichage argent
    sf::Text a_dollars(std::to_string(Tresor.getDollars()), font, 25);

    //affichage vie
    sf::Text a_vie(std::to_string(listeMineurs[0].getVie()), font, 25);

    //affichage pépites d'or

    sf::Text a_or(std::to_string(Tresor.getOr()), font, 25);

    //affichage moral
    sf::Text a_moral(std::to_string(listeMineurs[0].getMoral()), font, 25);

    //affichage tour
    sf::Text a_tour(std::to_string(Tour.getNbTour()), font, 25);

    //affichage du texte
    std::string m1;
    std::string m2;
    m1=Tour.getLigne1();
    m2=Tour.getLigne2();
    sf::Text titre1(m1, font, 25);
    sf::Text titre2(m2, font, 25);



  ///////

    //ecran d'acceil
    sf::Texture t0;
    t0.loadFromFile("accueil.jpg");

    //image de font mine
    sf::Texture t1;
    t1.loadFromFile("imagesModif.jpg");

    //image de font ville
    sf::Texture t2;
    t2.loadFromFile("villeModif.jpg");

    //image game over
    sf::Texture t3;
    t3.loadFromFile("gameover.jpg");

    //on definie le sprite, par défault l'écran titre
    sf::Sprite sprite;
    sprite.setTexture(t0);  



      while (window.isOpen()){
        // mise a jour du texte en haut
        sf::Text titre1(m1, font, 25); // pour actualiser le message
        titre1.setFillColor(sf::Color::Black);
        titre1.setPosition(10,10);

        // mise a jour de la seconde ligne
        sf::Text titre2(m2, font, 25); // pour actualiser le message
        titre2.setFillColor(sf::Color::Black);
        titre2.setPosition(10,50);

   
        //mise a jour affichage vie
        sf::Text a_vie("Vie :  " + std::to_string(listeMineurs[0].getVie()), font, 35); // pour actualiser le message
        a_vie.setFillColor(sf::Color::Black);
        a_vie.setPosition(0,145);

        //mise a jour affichage moral
        sf::Text a_moral("Moral :   " + std::to_string(listeMineurs[0].getMoral()), font, 35); // pour actualiser le message
        a_moral.setFillColor(sf::Color::Black);
        a_moral.setPosition(0,205);

        //mise a jour affichage pépites d'or
        sf::Text a_or("Or :    " + std::to_string(Tresor.getOr()), font, 35); // pour actualiser le message
        a_or.setFillColor(sf::Color::Black);
        a_or.setPosition(0,255);

        //mise a jour affichage dollars
        sf::Text a_dollars("Dollars :   " + std::to_string(Tresor.getDollars()), font, 35); // pour actualiser le message
        a_dollars.setFillColor(sf::Color::Black);
        a_dollars.setPosition(0,305);


        //mise a jour affichage tour
        sf::Text a_tour("Tour :   " + std::to_string(Tour.getNbTour()), font, 35); // pour actualiser le message
        a_tour.setFillColor(sf::Color::Black);
        a_tour.setPosition(0,357);


        sf::Event event;

        int x;
        int y;
        
        while (window.pollEvent(event)){


            //Game Over
            if (choixJoueur==0){
                tableau=3;
                sprite.setTexture(t3);  

            }



            // Si on parcours un icone avec la sourie
            if (event.type == sf::Event::MouseMoved){
     
                x=sf::Mouse::getPosition(window).x;    
                y=sf::Mouse::getPosition(window).y;


                if (tableau==1){ 
                    sprite.setTexture(t1);
                    m1="Te voici dans ta mine, que veux tu faire ?";
                    m2="";

                    if (y>490){

                        if ((x>375)&(x<505)){ //aller a la mine 

                            m1="Partir miner";
                                        
                        }

                        if ((x>505)&(x<625)){ //aller a la ville
                           
                            m1="Aller en ville";
                            m2="";

                        }      



                        if ((x>625)&(x<750)){ //se reposer
                           
                            m1="Se reposer";
                            m2="";
                        }

                        if ((x>750)&(x<850)){

                            m1="Lancer une attaque de bandits";
                            m2="";

                        }
                         
                           
                    }
                }   

                if (tableau==2){
                    sprite.setTexture(t2);
                    m1="Bienvenue en ville";
                    m2="";
                    
                    
                    if (y>490){
                        if ((x>375)&(x<505)){ //vendre son or

                            m1="Vendre ton or";
                            m2="";
                                                  
                        }

                        if ((x>505)&(x<625)){ //se soigner
                
                            m1="Te soigner (100$ le point de vie)";
                            m2="";  
                        }   

                        if ((x>625)&(x<750)){ //recruter un mineur
                           
                            m1="Recruter un mineur (1000$ pour l'embauche puis 3$ par tour)";
                            m2="";
                                
                        }

                        if ((x>750)&(x<850)){

                            m1="Recruter un bandit (100$ pour l'embauche)";
                            m2="";
                        }  
                    }

                    if ((x>895)&(x<1000)&(y>128)&(y<208)){

                        m1="Retourner dans ta mine";
                        m2="";

                    }  
                }
            }


            







            ////////////////////// 


            //Si on clique avec la sourie
            if (event.type == sf::Event::MouseButtonReleased){

            //Position du clic stockée dans event.MouseButton.x et event.MouseButton.y
        
                x=event.mouseButton.x;
                y=event.mouseButton.y;

               
                affichage=Tour.gestionChaos(CHAOS,listeMineurs,listeBandits,Tresor);


/*
                //// tricher en cliquant sur la boîte aux lettres////

                if ((x>445) & (x<515) & (y>335) & (y<400)){

                    choixJoueur=Tour.suivant(9,Anzin,Tresor,listeMineurs[0],listeMineurs,listeBandits,CHAOS);
                }*/
                
                //// ecran titre ////   
                if (tableau==0){
                    tableau=1;
                }
                
                /////// La mine ////////
                if (tableau==1){ 
                    sprite.setTexture(t1);
                    m1="Te voici dans ta mine, que veux tu faire ?";
                    m2="";

                    if (y>490){
                        if ((x>375)&(x<505)){ //aller a la mine 
                    
                            choixJoueur=1;

                            Tour.description(choixJoueur);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();

                            choixJoueur=Tour.suivant(choixJoueur,Anzin,Tresor,listeMineurs[0],listeMineurs,listeBandits,CHAOS);

                            Tour.description(affichage);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();
    

                                        
                        }

                        if ((x>505)&(x<625)){ //aller a la ville
                           
                            tableau=2;
                            sprite.setTexture(t2);
                            x=0;
                            y=0;

                        }      

                        if ((x>625)&(x<750)){ //se reposer
                           
                            choixJoueur=2;
                            Tour.description(choixJoueur);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();
                            choixJoueur=Tour.suivant(choixJoueur,Anzin,Tresor,listeMineurs[0],listeMineurs,listeBandits,CHAOS);

                            Tour.description(affichage);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();
                        
                         
                        }   

                        if ((x>750)&(x<850)){
                            
                            choixJoueur=8;
                            choixJoueur=Tour.suivant(choixJoueur,Anzin,Tresor,listeMineurs[0],listeMineurs,listeBandits,CHAOS);
                            Tour.description(choixJoueur);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();

                            Tour.description(affichage);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();

                        

                        }
                    }
                }
                
                /////////  La ville ///////
                if (tableau==2){
                    sprite.setTexture(t2);
                    m1="Bienvenue en ville";
                    m2="";
                    
                    if (y>490){
                        if ((x>375)&(x<505)){ //vendre son or

                            choixJoueur=4;
                            Tour.description(choixJoueur);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();
                            choixJoueur=Tour.suivant(choixJoueur,Anzin,Tresor,listeMineurs[0],listeMineurs,listeBandits,CHAOS);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();
                            tableau=1;  
                            sprite.setTexture(t1);

                            Tour.description(affichage);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();

                            x=0;
                            y=0;                    
                        }
                        if ((x>505)&(x<625)){ //se soigner
                    
                            choixJoueur=5;
                            Tour.description(choixJoueur);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();
                            choixJoueur=Tour.suivant(choixJoueur,Anzin,Tresor,listeMineurs[0],listeMineurs,listeBandits,CHAOS);
                            tableau=1;  
                            sprite.setTexture(t1);

                            Tour.description(affichage);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();

                            x=0;
                            y=0;      
                        }       
                        if ((x>625)&(x<750)){ //recruter un mineur
                           

                            choixJoueur=6;
                            choixJoueur=Tour.suivant(choixJoueur,Anzin,Tresor,listeMineurs[0],listeMineurs,listeBandits,CHAOS);
                            Tour.description(choixJoueur);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();
                            tableau=1;  
                            sprite.setTexture(t1);

                            Tour.description(affichage);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();

                            x=0;
                            y=0; 

                        } 

                        if ((x>750)&(x<850)){

                            choixJoueur=7;
                            choixJoueur=Tour.suivant(choixJoueur,Anzin,Tresor,listeMineurs[0],listeMineurs,listeBandits,CHAOS);
                            Tour.description(choixJoueur);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();
                            tableau=1;  
                            sprite.setTexture(t1);


                            Tour.description(affichage);
                            m1=Tour.getLigne1();
                            m2=Tour.getLigne2();

                            x=0;
                            y=0; 

                        }
                    }

                     if ((x>895)&(x<1000)&(y>128)&(y<208)){

                        tableau=1;
                        sprite.setTexture(t1);
                        x=0;
                        y=0;
                        
                    } 
                }  
            }

            if (event.type == sf::Event::Closed)  window.close();
        }



        //affichage
        window.clear();
        window.draw(sprite);       
        window.draw(titre1);
        window.draw(titre2);
        window.draw(a_vie);
        window.draw(a_moral);
        window.draw(a_or);
        window.draw(a_dollars);
        window.draw(a_tour);
        window.display();
        //std::cout<<tableau<<std::endl;  //retourne le numero du tableau actuel
    }

    return (0);
}

