#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Numbers are taken from this website http://darksouls3.wikidot.com/weapons starting from top left to bottom right.
//Offhands are taken from http://darksouls3.wikidot.com/shields and http://darksouls3.wikidot.com/spell-tools, starting
//with shields as 1, and spell stuff after the shields.

int main (void){

	FILE *wep, *off, *hel, *che, *han, *leg, *rin, *fou;
    int main_id, off_id, i, helm_id, chest_id, hand_id, leg_id, r1, r2, r3, r4, rr;
	char mainh[185][30], offh[97][30], helm[79][30], chest[85][30], hands[73][30], legs[77][30], ring[71][35], reroll;
    srand((unsigned) time (NULL));

    wep = fopen("weapon.txt", "r");
	off = fopen("offhand.txt", "r");
	hel = fopen("helmet.txt", "r");
	che = fopen("chest.txt", "r");
	han = fopen("hands.txt", "r");
	leg = fopen("legs.txt", "r");
	rin = fopen("ring.txt", "r");
	fou = fopen("build.txt", "w");
	
	rr = 1;

	for(i = 0;i<185;i++){
		fgets(mainh[i+1], 30, wep);
	}
	for(i = 0; i<97;i++){
		fgets(offh[i+1], 30, off);
	}
	for(i = 0; i<79;i++){
		fgets(helm[i+1], 30, hel);
	}
	for(i = 0; i<85;i++){
		fgets(chest[i+1], 30, che);
	}
	for(i = 0; i<73;i++){
		fgets(hands[i+1], 30, han);
	}
	for(i = 0; i<77;i++){
		fgets(legs[i+1], 30, leg);
	}
	for(i = 0; i<71;i++){
		fgets(ring[i+1], 35, rin);
	}

    do{

        main_id = (rand()%184) + 1;
        off_id = (rand()%96) + 1;
        helm_id = (rand()%78) + 1;
        chest_id = (rand()%84) + 1;
        hand_id = (rand()%72) + 1;
        leg_id = (rand()%76) + 1;
        r1 = (rand()%70) + 1;
        r2 = (rand()%70) + 1;

        while(1 == 1){
        if(r1 != r2){
            break;
        }
        else r2 = (rand()%70) + 1;
        }
        r3 = (rand()%70) + 1;
        while(1 == 1){
        if(r3 != r1 && r3 != r2){
            break;
        }
        else r3 = (rand()%70) + 1;
        }

        r4 = (rand()%70) + 1;

        while(1 == 1){
        if(r4 != r3 && r4 != r2 && r4 != r1){
            break;
        }
        else r4 = (rand()%70) + 1;
        }

        printf("Your main hand weapon is %d, %s\n", main_id, mainh[main_id]);
        printf("Your off hand weapon is %d, %s\n", off_id, offh[off_id]);
        printf("Your helmet is %d, %s\n", helm_id, helm[helm_id]);
        printf("Your chest piece is %d, %s\n", chest_id, chest[chest_id]);
        printf("Your gloves are %d, %s\n", hand_id, hands[hand_id]);
        printf("Your legs are %d, %s\n", leg_id, legs[leg_id]);
        printf("Your rings are: \n%s%s%s%s\n", ring[r1], ring[r2], ring[r3], ring[r4]);


        printf("Would you like to re-roll your choices?(Y/N)\n");
        scanf("%c", &reroll);

        if(reroll != 'Y' && reroll != 'y' && reroll != 'n' && reroll != 'n'){
            do{
                printf("Please input Y for yes, or N for no.\n");
                scanf("%c", &reroll);
            }while(reroll != 'Y' && reroll != 'y' && reroll != 'n' && reroll != 'n');
        }

        switch(reroll){
        case 'Y' :
            rr = 1;
            break;
        case 'y' :
            rr = 1;
            break;
        case 'n':
            rr = 0;
            break;
        case 'N':
            rr = 0;
            break;
        }

        printf("---------------------------------------------------------------------------------------\n");

    }while(rr == 1);

    printf("This is what you rolled, now deal with it, fuck you.\n - Jarrod 2018\n");
	
	fprintf(fou, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "Your build: ", mainh[main_id], offh[off_id], helm[helm_id], chest[chest_id], hands[hand_id], legs[leg_id], ring[r1], ring[r2], ring[r3], ring[r4]);

	fclose(wep);
	fclose(off);
	fclose(hel);
	fclose(che);
	fclose(han);
	fclose(leg);
	fclose(rin);
	fclose(fou);

	system("PAUSE");
    return 0;
}
