//Petr Grajciar, 2.B, PVA Bojová aréna, 2.6.2021

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

float winrate(float vyhra, int pocetHer){
    
    float winrate;

    winrate = (vyhra / pocetHer) * 100;

    return winrate;
}

int arena(char name[], int hp, int damage){

    char oponenti[][15] = {"Azog", "SAMS", "Destroyer", "HopperW12", "Zugabuk", "Yasuo", "StileSam", "IN5I", "Risanek1717", "basicalyOndra", "NOVO", "Baky", ":)"};
    int index, akce, cooldown = 0, cooldown_ai = 0, zapas;
    int ai;
    bool probihajici_hra = true;

    struct Oponent{
        char name[15];
        int hp;
        int damage;
    };
    
    printf("===== Zacatek boje =====\n");

    struct Oponent oponent;

    index = rand() % 13;
    strcpy(oponent.name, oponenti[index]);
    oponent.hp = hp - rand() % 5;
    oponent.damage = damage;

    printf("V arene se utka hrac %s proti %s\n", name, oponent.name);

    char* bojovnici[2] = {name, oponent.name};

    int zacina;
    zacina = rand() % 2;

    printf("Zacina hrac %s\n", bojovnici[zacina]);

    printf("Zivoty hrace %s: %d HP\n", name, hp);
    printf("Zivoty hrace %s: %d HP\n\n", oponent.name, oponent.hp);

    while(probihajici_hra){

        ai = rand() % 3;

        if(zacina == 0){

            printf("\nVyberte si akci:\n");
            printf("- Zadej 1 pro lehky utok\n- Zadej 2 pro tezky utok\n");
            scanf("%d", &akce);
            printf("\n");

            if(akce == 1){

                oponent.hp = oponent.hp - (damage + rand() % 5);
                printf("%s utoci\n", name);
                printf("Zivoty hrace %s: %d HP\n", oponent.name, oponent.hp);

                if(oponent.hp <= 0){

                    printf("\nVyhral hrac %s\n", name);
                    printf("Gratulujeme k vyhre!\n");
                    zapas = 1;
                    return zapas;
                    probihajici_hra = false;
                }

                if(ai == 0){
                    hp = hp - (oponent.damage + rand() % 5);
                    printf("%s utoci\n", oponent.name);
                    printf("Zivoty hrace %s: %d HP\n", name, hp);
                }
                else if(ai == 1){
                    hp = hp - (oponent.damage + rand() % 5);
                    printf("%s utoci\n", oponent.name);
                    printf("Zivoty hrace %s: %d HP\n", name, hp);
                }
                else{
                    if(cooldown_ai == 0){
                        hp = hp - (oponent.damage + rand() % 10);
                        printf("%s utoci\n", oponent.name);
                        printf("Zivoty hrace %s: %d HP\n", name, hp);
                        cooldown_ai = 3;
                    }
                    else{
                        hp = hp - (oponent.damage + rand() % 5);
                        printf("%s utoci\n", oponent.name);
                        printf("Zivoty hrace %s: %d HP\n", name, hp);
                    }
                }

                if(hp <= 0){

                    printf("\nVyhral hrac %s\n", oponent.name);
                    printf("Litujeme, ale prohral jste, pro priste vam prejeme vice stesti!\n");
                    zapas = 0;
                    return zapas;
                    probihajici_hra = false;
                }
            }

            else if(akce == 2){

                if(cooldown == 0){

                    oponent.hp = oponent.hp - (damage + rand() % 10);
                    printf("%s utoci\n", name);
                    printf("Zivoty hrace %s: %d HP\n", oponent.name, oponent.hp);
                    cooldown = 3;
                }
                else{

                    oponent.hp = oponent.hp - (damage + rand() % 5);
                    printf("%s utoci\n", name);
                    printf("Zivoty hrace %s: %d HP\n", oponent.name, oponent.hp);
                }

                if(oponent.hp <= 0){

                    printf("\nVyhral hrac %s\n", name);
                    printf("Gratulujeme k vyhre!\n");
                    zapas = 1;
                    return zapas;
                    probihajici_hra = false;
                }

                if(ai == 0){

                    hp = hp - (oponent.damage + rand() % 5);
                    printf("%s utoci\n", oponent.name);
                    printf("Zivoty hrace %s: %d HP\n", name, hp);
                }
                else if(ai == 1){

                    hp = hp - (oponent.damage + rand() % 5);
                    printf("%s utoci\n", oponent.name);
                    printf("Zivoty hrace %s: %d HP\n", name, hp);
                }
                else{

                    if(cooldown_ai == 0){

                        hp = hp - (oponent.damage + rand() % 10);
                        printf("%s utoci\n", oponent.name);
                        printf("Zivoty hrace %s: %d HP\n", name, hp);
                        cooldown_ai = 3;
                    }
                    else{
                        hp = hp - (oponent.damage + rand() % 5);
                        printf("%s utoci\n", oponent.name);
                        printf("Zivoty hrace %s: %d HP\n", name, hp);
                    }
                }

                if(hp <= 0){

                    printf("\nVyhral hrac %s\n", oponent.name);
                    printf("Litujeme, ale prohral jste, pro priste vam prejeme vice stesti!\n");
                    zapas = 0;
                    return zapas;
                    probihajici_hra = false;
                }
            }
            else{

                printf("Neplatna akce!\n");
            }
        }

        else{

            if(ai == 0){

                hp = hp - (oponent.damage + rand() % 5);
                printf("%s utoci\n", oponent.name);
                printf("Zivoty hrace %s: %d HP\n", name, hp);
            }

            else if(ai == 1){

                hp = hp - (oponent.damage + rand() % 5);
                printf("%s utoci\n", oponent.name);
                printf("Zivoty hrace %s: %d HP\n", name, hp);
            }

            else{

                if(cooldown_ai == 0){

                    hp = hp - (oponent.damage + rand() % 10);
                    printf("%s utoci\n", oponent.name);
                    printf("Zivoty hrace %s: %d HP\n", name, hp);
                    cooldown_ai = 3;
                }
                else{

                    hp = hp - (oponent.damage + rand() % 5);
                    printf("%s utoci\n", oponent.name);
                    printf("Zivoty hrace %s: %d HP\n", name, hp);
                }
             }

            if(hp <= 0){

                printf("\nVyhral hrac %s\n", oponent.name);
                printf("Litujeme, ale prohral jste, pro priste vam prejeme vice stesti!\n");
                zapas = 0;
                return zapas;
                probihajici_hra = false;
            }
            else{

                printf("\nVyberte si akci:\n");
                printf("- Zadej 1 pro lehky utok\n- Zadej 2 pro tezky utok\n");
                scanf("%d", &akce);
                printf("\n");
            }
            

            if(akce == 1){

                oponent.hp = oponent.hp - (damage + rand() % 10);
                printf("%s utoci\n", name);
                printf("Zivoty hrace %s: %d HP\n", oponent.name, oponent.hp);

                if(oponent.hp <= 0){

                    printf("\nVyhral hrac %s\n", name);
                    printf("Gratulujeme k vyhre!\n");
                    zapas = 1;
                    return zapas;
                    probihajici_hra = false;
                }
            }
            else if(akce == 2){

                if(cooldown == 0){

                    oponent.hp = oponent.hp - (damage + rand() % 10);
                    printf("%s utoci\n", name);
                    printf("Zivoty hrace %s: %d HP\n", oponent.name, oponent.hp);
                    cooldown = 3;
                }
                else{

                    oponent.hp = oponent.hp - (damage + rand() % 5);
                    printf("%s utoci\n", name);
                    printf("Zivoty hrace %s: %d HP\n", oponent.name, oponent.hp);
                }

                if(oponent.hp <= 0){

                    printf("\nVyhral hrac %s\n", name);
                    printf("Gratulujeme k vyhre!\n");
                    zapas = 1;
                    return zapas;
                    probihajici_hra = false;
                }
            }
            else{

                printf("Neplatna akce!\n");
            }
        }

        if(cooldown != 0){
            cooldown--;
        }
        if(cooldown_ai != 0){
            cooldown_ai--;
        }
    }

    return 0;
}

int main(void){

    char prikaz[10];
    int hry = 0, vyhry = 0, hra;
    float wr;

    int xp = 0;
    int level = 0;

    //Class v jazyce C
    struct Bojovnik{
        char name[20];
        int hp;
        int damage;
    };

    struct Bojovnik fighter;

    srand(time(NULL));

    printf("========== Bojova arena ==========\n");

    //Zadání přezdívky a základní údaje o postavě
    printf("Zadejte vasi prezdivku: ");
    scanf("%s", &fighter.name);

    while(1){

        fighter.hp = 100 * (1 + (level * 0.25));
        fighter.damage = (20 + (level * 2));

        printf("Zadej prikaz, popripade pouzij prikaz |help|: ");
        scanf("%s", &prikaz);

        //Příkaz, který ukončí program
        if(strcmp(prikaz, "exit") == 0){

            printf("Ukoncuji program...\n");
            exit(EXIT_SUCCESS);
        }
        //Příkaz, který vám vypíše všechny možné příkazy
        else if(strcmp(prikaz, "help") == 0){

            printf("=== SEZNAM PRIKAZU ===\n");
            printf("- arena - Vstoupite do areny\n");
            printf("- winrate - Zobrazi vam vas pomer vyher a proher\n");
            printf("- info - Zobrazi vam aktualni status vasi postavy\n");
            printf("- exit - Vypnuti programu\n");
            printf("======================\n");
        }
        //Příkaz, který vám vypíše aktuální status vaší postavy
        else if(strcmp(prikaz, "info") == 0){
            printf("\nVase prezdivka: %s", fighter.name);
            printf("\nVas rank: ");

            switch(level){
                case 1:
                    printf("Zelezna");
                    break;
                case 2:
                    printf("Bronzova");
                    break;
                case 3:
                    printf("Stribrna");
                    break;
                case 4:
                    printf("Zlata");
                    break;
                case 5:
                    printf("Platinova");
                    break;
                case 6:
                    printf("Diamantova");
                    break;
                case 7:
                    printf("Legendarni");
                    break;
                default:
                    printf("Nehodnocena");
            }

            printf("\nPocet XP: %d/100\n", xp);
            printf("Pocet HP: %d\n", fighter.hp);
            printf("Vas damage: %d\n\n", fighter.damage);
        }
        //Zjištění poměru výher a proher
        else if(strcmp(prikaz, "winrate") == 0){

            wr = winrate(vyhry, hry);
            printf("Winrate: %.2f %%, Pocet her: %d, Vyhry: %d, Prohry: %d\n", wr, hry, vyhry, (hry - vyhry));
        }
        //Vstup do arény
        else if(strcmp(prikaz, "arena") == 0){

            hra = arena(fighter.name, fighter.hp, fighter.damage);
            vyhry += hra;

            if(hra == 1){
                xp += (rand() % 25) + 15;
            }
            else{
                xp += (rand() % 15) + 10;
            }

            hry++;
        }

        else{

            printf("Neznamy prikaz!\n");
        }

        if((xp >= 100) && (level <= 7)){
            xp = 0;
            level++;
        }
        if(level == 7){
            printf("\nGratuluji vam, dosahl jste nejvyssiho ranku v teto hre!\n");
        }
    }

    return 0;
}