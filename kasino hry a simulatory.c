// https://github.com/Tobiswaggy/CasinoSim/blob/main/kasino%20hry%20a%20simulatory.c

	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
    #include <unistd.h>

//zdroj: StackOverflow
void generateNumber(){
	static int initialized = 0;
		if (!initialized){
			srand(time(NULL));
			initialized = 1;
	}
}

int returnCoinflip(){
	return rand() % 2;
}

int returnDice(){
	return rand() % 6 + 1;
}

int returnSlot(){
	return rand() % 9 + 1;
}

int returnScratch(){
	return rand() % 5 + 1;
}

int pocetGolu(){
	return rand() % 8 + 2;
}

int tymyGoly(){
	return rand() % 100 + 1;
}

int main(){
	
		char rozhodnutiMince;
	
	float balance = 1000;
	
	
		unsigned long long i; // hlavni ridici promenna	
		unsigned long long random;
	
		unsigned long long heads = 0; //panna
		unsigned long long tails = 0; //orel
		
		int decisionCount; // kolikrat bude mince hozena
		char decisionShow; // vypisovat jednotlive? (Y/N)
		
			int diceRoll; // vygenerovana kostka
			int diceGuess; 
			
			int diceSimulator; // porovnavani ve for cyklu
			char diceDecision; // Y/N
			
			// jednotlive pocty vygenerovanych kostek, inkrementovany...
			unsigned long long diceOnes = 0;
			unsigned long long diceTwos = 0;
			unsigned long long diceThrees = 0;
			unsigned long long diceFours = 0;
			unsigned long long diceFives = 0;
			unsigned long long diceSixes = 0;
			
			int diceMenu;
	
			int slotOne; // policko automatu cislo 1
			int slotTwo; // policko automatu cislo 2
			int slotThree; // policko automatu cislo 3
		
			int slotBet; // sazka na automatu
			int slotWin; // vyhra na automatu pricitana k promenne int balance
			
			int animace[16] = {9, 5, 3, 2, 4, 8, 9, 1, 3, 6, 7, 4, 9, 5, 2, 1};
			int k; // rizeni for cyklu pro animaci
			int l; // rizeni for cyklu pro animaci
			
			int slotMenu; // re-roll herniho automatu
			
			int decisionMenu; // hlavni do-while a switch-case
			
			// mezivypocty pro procentualni pomer
			float vypocet1;
			float vypocet2;
			float vypocet3;
			float vypocet4;
			float vypocet5;
			float vypocet6;

			int losyMenu; //do-while a switch-case
			int losGenerator; //vygenerovane policko
			int policko1; //zobrazene policko 1
			int policko2; // zobrazene policko 2
			int policko3; // zobrazene policko 3
			
			int sportMenu; // menu pro sazeni na sport
			int prvniGolyT1 = 0; // goly tym 1
			int prvniGolyT2 = 0; // goly tym 2
			int druhyGolyT1 = 0;
			int druhyGolyT2 = 0;
			int tretiGolyT1 = 0;
			int tretiGolyT2 = 0;
			int presnyPocetGolu1;
			int presnyPocetGolu2;
			int presnyPocetGolu3;
			float sazkaGoly1;
			float sazkaGoly2;
			float sazkaGoly3;
			float vyhraGoly1;
			float vyhraGoly2;
			float vyhraGoly3;
			float sportSazka1; // kolik vsadil uzivatel
			float sportSazka2;
			float sportSazka3;
			float sportVyhra1; // kolik vyhral uzivatel
			float sportVyhra2;
			float sportVyhra3;
			int hideFirst = 0; // jakmile jednou vsadil na zapas, uz se nebude objevovat v tabulce
			int hideSecond = 0; // jakmile jednou vsadil na zapas, uz se nebude objevovat v tabulce
			int hideThird = 0; // jakmile jednou vsadil na zapas, uz se nebude objevovat v tabulce
			int vysledekPrvni; // tip uzivatele na zapas 1
			int vysledekDruhy; // tip uzivatele na zapas 2
			int vysledekTreti; // tip uzivatele na zapas 3
			int goalsInMatch; // kolik golu padne v zapase
			int s; // ridici promena cyklu
			int mezivypocetGoly;
			int mezivypocetGoly1;
			int mezivypocetGoly2;
			int mezivypocetGoly3;
			char rozhodnutiGoly1;
			char rozhodnutiGoly2;
			char rozhodnutiGoly3;
			
	do{
		
			printf("\n");
	
	//Zjednodusena verze | Posledni update: 23/3/2024 | Skolni projekt, vytvoril Hlozek
	printf("\thttps://github.com/Tobiswaggy\n"); 
	printf("\n");
	
printf("\t   :::     ::: :::::::::: ::::::::      :::      ::::::::\n"); 
printf("\t  :+:     :+: :+:       :+:    :+:   :+: :+:   :+:    :+:\n"); 
printf("\t +:+     +:+ +:+       +:+         +:+   +:+  +:+        \n"); 
printf("\t+#+     +:+ +#++:++#  :#:        +#++:++#++: +#++:++#++  \n"); 
printf("\t+#+   +#+  +#+       +#+   +#+# +#+     +#+        +#+   \n"); 
printf("\t#+#+#+#   #+#       #+#    #+# #+#     #+# #+#    #+#    \n"); 
printf("\t ###     ########## ########  ###     ###  ########      \n\n");                                       
                                          	
	printf("\t1. Hod minci\n");
	printf("\t2. Hod kostkou\n");
	printf("\t3. Herni automat\n");
	printf("\t4. Stiraci losy\n");
	printf("\t5. Sportovni zapasy\n");
	printf("\t6. Zustatek herniho uctu\n");
	printf("\t7. Credits\n");
	printf("\t8. Ukoncit program\n");
	printf("\n\tZadej moznost: ");
	scanf("%d", &decisionMenu);
	
	if(decisionMenu < 1 && decisionMenu > 8){
		printf("\n\tNeplatna moznost.\n\t");
		return 0;
	}
	
	
	switch(decisionMenu){
		
	case 1: // hod minci
				
		// program dokaze hodit minci 18446744073709551615 krat
	do{
	
	printf("\n");
	printf("\tHod minci\n");
	
	printf("\tKolikrat si prejes hodit minci? ");
	scanf("%d", &decisionCount);
	
	
	if(decisionCount <= 0){
		printf("\tMince musi byt hozena alespon jednou!");
		return 0;
	}
	
	printf("\tVarovani! Prilis velka hodnota muze zpusobit zaseknuti programu!\n");
	printf("\tPrejes si, aby program vypisoval jednotlivy hod mince? (Y/N): ");
	scanf(" %c", &decisionShow);
	
	
	if(decisionShow != 'y' && decisionShow != 'Y' && decisionShow != 'n' && decisionShow != 'N'){
		printf("\n");
		printf("\tNeplatna odpoved!");
		return 0;
	}
	
	for(i = 1; i <= decisionCount; i++){
		
		generateNumber();
		random = returnCoinflip();
		
		if(random == 0){
			
			if(decisionShow == 'y' || decisionShow == 'Y'){
			printf("\tHod cislo %d - Panna\n", i);
			}
			
			heads++;
			
		}else if(random == 1){
			
			if(decisionShow == 'y' || decisionShow == 'Y'){
			printf("\tHod cislo %d - Orel\n", i);
			}
			
			tails++;
		}
			
	}
	
	printf("\n");
	
	printf("\tMince byla hozena %d krat.\n", decisionCount);

	printf("\n");
	
	printf("\tPanna: %d\n", heads);
	printf("\tOrel: %d", tails);
	
	printf("\n");
		
		float ratioHeads = ((float)heads / decisionCount) * 100;
		float ratioTails = ((float)tails / decisionCount) * 100;
		
	printf("\tProcentualni pomer: ");
	printf("\t%.2f%% | ", ratioHeads);
	printf("\t%.2f%%", ratioTails);
	
	printf("\n");
	printf("\n");
	
	printf("\tPrejes si hrat znovu? (Y/N): ");
	scanf(" %c", &rozhodnutiMince);
	
	if(rozhodnutiMince != 'n' && rozhodnutiMince != 'y'){
		printf("\n");
		printf("\tNeplatna moznost!\n");
		system("PAUSE");
		return 0;
	}	
	
	system("cls");
			
}while(rozhodnutiMince != 'n');

		break;
		


		
		case 2: // hod kostkou
		

			
			do{
							printf("\n");
		
			printf("\tHod kostkou\n");
			
			printf("\n");
			
			printf("\t1. Simulator hodu kostkou\n");
			printf("\t2. Zpatky do menu\n");
			
			printf("\n");
			
			printf("\tZadej moznost: ");
			scanf("%d", &diceMenu);
			
			if(diceMenu != 1 && diceMenu != 2 && diceMenu != 3){
				printf("\tToto neni platna moznost!\n");
				system("PAUSE");
				return 0;
			}
				
				switch(diceMenu){
					
					case 1:
						
						printf("\tKolikrat si prejes hodit kostkou? ");
						scanf("%d", &diceSimulator);
						
						printf("\tVarovani! Prilis velka hodnota muze zpusobit zaseknuti programu!\n");
						
						printf("\tPrejes si, aby program vypisoval jednotlivy hod kostkou? (Y/N): ");
						scanf(" %c", &diceDecision);
						
						if(diceDecision != 'y' && diceDecision != 'Y' && diceDecision != 'n' && diceDecision != 'M'){
							printf("\tToto neni platna moznost!\n");
							return 0;
						}
						
						for(i=0; i < diceSimulator; i++){
							
							generateNumber();
							diceRoll = returnDice();
							
							if(diceDecision == 'y'){
								printf("\tHod kostkou cislo %d: %d\n", i, diceRoll);
							}
							
							if(diceRoll == 1){
								
								diceOnes++;
								
							}else if(diceRoll == 2){
								
								diceTwos++;
								
							}else if(diceRoll == 3){
								
								diceThrees++;
								
							}else if(diceRoll == 4){
								
								diceFours++;
								
							}else if(diceRoll == 5){
								
								diceFives++;
								
							}else if(diceRoll == 6){
								
								diceSixes++;
								
							}
						}
						
						float vypocet1 = ((float)diceOnes / diceSimulator) * 100;
						float vypocet2 = ((float)diceTwos / diceSimulator) * 100;
						float vypocet3 = ((float)diceThrees / diceSimulator) * 100;												
						float vypocet4 = ((float)diceFours / diceSimulator) * 100;						
						float vypocet5 = ((float)diceFives / diceSimulator) * 100;						
						float vypocet6 = ((float)diceSixes / diceSimulator) * 100;
						
						printf("\n\tBylo hozeno celkem %d kostek.\n", i);
						printf("\n\tProcentualni pomery:\n");
						
						printf("\n\tJednicky: %d | %.2f%%\n", diceOnes, vypocet1);
						printf("\tDvojky: %d | %.2f%%\n", diceTwos, vypocet2);
						printf("\tTrojky: %d | %.2f%%\n", diceThrees, vypocet3);
						printf("\tCtyrky: %d | %.2f%%\n", diceFours, vypocet4);
						printf("\tPetky: %d | %.2f%%\n", diceFives, vypocet5);
						printf("\tSestky: %d | %.2f\n", diceSixes, vypocet6);											
						
					break;
					
				}
				
				printf("\n");
				printf("\t");
				system("PAUSE");
				system("cls");
				
			}while(diceMenu != 2);
			
			
		break;
			
		case 3: // automat
		printf("\n");
			printf("\tHerni automat\n");
			printf("\n\tPravidla:\n");
			printf("\n\tJedna sedmicka - cashback\n");
			printf("\tDve sedmicky - 7x payout\n");
			printf("\tTri sedmicky - 77x payout\n");
			printf("\t2 stejna cisla - 2x payout\n");
			printf("\t3 stejna cisla - 33x payout\n");
			printf("\n");
			
			do{
				
				printf("\tZadej sazku: ");
				scanf("%d", &slotBet);
				
					if(slotBet > balance)
					{
						printf("\n");
						printf("\tNemas dostatek financi!\n");
						printf("\t");
						system("PAUSE");
						return 0;	
					}					
	
					balance = balance - slotBet;

			
				
				generateNumber();
				slotOne = returnSlot();
				
				generateNumber();
				slotTwo = returnSlot();
				
				generateNumber();
				slotThree = returnSlot();
				
				printf("\n");
				
					printf("\tRESETTING.\n");
					sleep(1);
					printf("\tRESETTING..\n");
					sleep(1);
					printf("\tRESETTING...\n");
					sleep(1);
				
						printf("\n");
						printf("\t____________________________\n");
						printf("\t|                           |\n");						
						printf("\t|    777 LUCK MASTER 777    |\n");
						printf("\t|________ __________________|\n");
						printf("\t|        |        |         |\n");
						printf("\t|   [?]  |   [?]  |   [?]   |\n");
						printf("\t|________|________|_________|\n");
						printf("\t|                           |\n");						
						printf("\t|        PLAY TO WIN        |\n");
						printf("\t|   YOU ARE ONE SPIN AWAY   |\n");
						printf("\t|___________________________|\n");
						
						printf("\t");
						system("PAUSE");
						system("cls");
						
						printf("\n");
						for(k=0; k<7; k++){

						printf("\t____________________________\n");
						printf("\t|                           |\n");						
						printf("\t|    777 LUCK MASTER 777    |\n");
						printf("\t|________ __________________|\n");
						printf("\t|        |        |         |\n");
												sleep(0.2);
						printf("\t|   %d    |   %d    |   [?]   |\n", slotOne, animace[k]);
						printf("\t|________|________|_________|\n");
						printf("\t|                           |\n");						
						printf("\t|        PLAY TO WIN        |\n");
						printf("\t|   YOU ARE ONE SPIN AWAY   |\n");
						printf("\t|___________________________|\n");
						system("cls");
				}

						for(l=0; l<7; l++){						
						printf("\n");
						printf("\t____________________________\n");
						printf("\t|                           |\n");						
						printf("\t|    777 LUCK MASTER 777    |\n");
						printf("\t|________ __________________|\n");
						printf("\t|        |        |         |\n");
						printf("\t|   %d    |   %d    |   %d    |\n", slotOne, slotTwo, animace[l]);
						printf("\t|________|________|_________|\n");
						printf("\t|                           |\n");						
						printf("\t|        PLAY TO WIN        |\n");
						printf("\t|   YOU ARE ONE SPIN AWAY   |\n");
						printf("\t|___________________________|\n");
						system("cls");
}
						
						printf("\n");
						printf("\t____________________________\n");
						printf("\t|                           |\n");						
						printf("\t|    777 LUCK MASTER 777    |\n");
						printf("\t|________ __________________|\n");
						printf("\t|        |        |         |\n");
						printf("\t|   %d    |   %d    |   %d     |\n", slotOne, slotTwo, slotThree);
						printf("\t|________|________|_________|\n");
						printf("\t|                           |\n");						
						printf("\t|        PLAY TO WIN        |\n");
						printf("\t|   YOU ARE ONE SPIN AWAY   |\n");
						printf("\t|___________________________|\n");
						
						printf("\n");
										if(slotOne == 7 || slotTwo == 7 || slotThree == 7){
					slotWin = slotBet * 1.0;
					printf("\t1.0x payout. Vyhravas %d$\n", slotWin);
				}else if(slotOne == 7 && slotTwo == 7){
					slotWin = slotBet * 7;
					printf("\t7x payout. Vyhravas %d$\n", slotWin);
				}else if(slotTwo == 7 && slotThree == 7){
					slotWin = slotBet * 7;
					printf("\t7x payout. Vyhravas %d$\n", slotWin);
				}else if(slotOne == 7 && slotThree == 7){
					slotWin = slotBet * 7;
					printf("\t7x payout. Vyhravas %d$\n", slotWin);
				}else if(slotOne == 7 && slotTwo == 7 && slotThree == 7){
					slotWin = slotBet * 77;
					printf("\tJackpot! Vyhravas %d$\n", slotWin);
					
				}else if(slotOne == slotTwo || slotTwo == slotThree || slotOne == slotThree){
					slotWin = slotBet * 2;
					printf("\t2x payout. Vyhravas %d$\n", slotWin);
				}else if(slotOne == slotTwo && slotTwo == slotThree && slotOne == slotThree){
					slotWin = slotBet * 33;
					printf("\tJackpot! Vyhravas %d$\n", slotWin);
				}
				
				balance = balance + slotWin;
				printf("\tMas %.2f dolaru.\n", balance);
				printf("\n");
				

				printf("\n");
				printf("\t1 pro dalsi hru, 0 pro zastaveni: \n");
				scanf("%d", &slotMenu);
								
			}while(slotMenu != 0);
			
			printf("\t");
			system("PAUSE");
			system("cls");
			
		break;
		
		case 4:
			
					do{
					printf("\n");
					printf("\t1. Zlata perla | Cena: 50 dolaru\n");
					printf("\t2. Zpatky\n\n");
					
					printf("\tZadej moznost: ");
					scanf("%d", &losyMenu);	
					
						switch(losyMenu){
							case 1:
								
								balance = balance - 50;
								printf("\n");
								printf("\tZakoupil jsi los za 50$. Zbyva ti %.2f$", balance);
								
								printf("\n");
						printf("\t____________________________\n");
						printf("\t|        ZLATA PERLA        |\n");
						printf("\t|___________________________|\n");
						printf("\t|        |        |         |\n");
						printf("\t|   [?]  |   [?]  |   [?]   |\n");
						printf("\t|________|________|_________|\n");
						printf("\t| 2x stejne cislo: 100$     |\n");
						printf("\t| 3 stejna cisla = 1,000$   |\n");
						printf("\t|___________________________|\n");
						printf("\t| Hodne stesti preje Sazka! |\n");
						printf("\t|___________________________|\n");
						
						printf("\t");
						system("PAUSE");
						system("cls");
						
						generateNumber();
						policko1 = returnScratch() * 10;
						
								printf("\n");
						printf("\t____________________________\n");
						printf("\t|        ZLATA PERLA        |\n");
						printf("\t|___________________________|\n");
						printf("\t|        |        |         |\n");
						printf("\t|   %d   |   [?]  |   [?]   |\n", policko1);
						printf("\t|________|________|_________|\n");
						printf("\t| 2x stejne cislo: 100$     |\n");
						printf("\t| 3 stejna cisla = 1,000$   |\n");
						printf("\t|___________________________|\n");
						printf("\t| Hodne stesti preje Sazka! |\n");
						printf("\t|___________________________|\n");		
								
								
						printf("\t");
						system("PAUSE");
						system("cls");
						
						generateNumber();
						policko2 = returnScratch() * 10;						

								printf("\n");
						printf("\t____________________________\n");
						printf("\t|        ZLATA PERLA        |\n");
						printf("\t|___________________________|\n");
						printf("\t|        |        |         |\n");
						printf("\t|   %d   |   %d   |   [?]   |\n", policko1, policko2);
						printf("\t|________|________|_________|\n");
						printf("\t| 2x stejne cislo: 100$     |\n");
						printf("\t| 3 stejna cisla = 1,000$   |\n");
						printf("\t|___________________________|\n");
						printf("\t| Hodne stesti preje Sazka! |\n");
						printf("\t|___________________________|\n");
							

						printf("\t");
						system("PAUSE");
						system("cls");
						
						generateNumber();
						policko3 = returnScratch() * 10;
						
								printf("\n");
						printf("\t____________________________\n");
						printf("\t|        ZLATA PERLA        |\n");
						printf("\t|___________________________|\n");
						printf("\t|        |        |         |\n");
						printf("\t|   %d   |   %d   |   %d    |\n", policko1, policko2, policko3);
						printf("\t|________|________|_________|\n");
						printf("\t| 2x stejne cislo: 100$     |\n");
						printf("\t| 3 stejna cisla = 1,000$   |\n");
						printf("\t|___________________________|\n");
						printf("\t| Hodne stesti preje Sazka! |\n");
						printf("\t|___________________________|\n");
										
							if(policko1 == policko2 && policko2 == policko3 && policko1 == policko3){
								printf("\n");
								printf("\tVyhravas 1000 dolaru!\n");
								balance = balance + 1000;
							}else if(policko1 == policko2){
								printf("\n");
								printf("\tVyhravas 100 dolaru!\n");
								balance = balance + 100;								
							}else if(policko2 == policko3){
								printf("\n");
								printf("\tVyhravas 100 dolaru!\n");
								balance = balance + 100;
							}else if(policko1 == policko3){
								printf("\n");
								printf("\tVyhravas 100 dolaru!\n");
								balance = balance + 100;
							}else{
								printf("\n");
								printf("\tTento los bohuzel nebyl vyherni...\n");
							}
										
							printf("\n");
							printf("\tNovy stav konta: %.2f\n", balance);
							printf("\n");
							printf("\t");
							system("PAUSE");
							system("cls");
						
						break;
						
					}
					
					}while(losyMenu != 2);	
					
					printf("\t");
					system("PAUSE");
					system("cls");
					
		break;

// SPORTOVNI SAZENI 


		case 5:
			
			
			do{
				printf("\n\tSazeni na sportovni zapasy\n");
				
				if(hideFirst == 0){
				printf("\t1. FINALE TELH - HC Dynamo Pardubice vs. HC Sparta Praha\n");
				}else if(hideFirst == 1){
				printf("\t1. Tento zapas skoncil. Jiz neni mozne si na nej vsadit.\n");
				}
				
				if(hideSecond == 0){
				printf("\t2. Druha ceska hokejova liga - HK Ostrava Poruba vs. HK Usti nad Labem\n");
				}else if(hideFirst == 1){
				printf("\t2. Tento zapas skoncil. Jiz neni mozne si na nej vsadit.\n");
				}
				
				if(hideThird == 0){
				printf("\t3. Prvni mexicka fotbalova liga - FC Mexico City vs. FC Tijuana\n");
				}else if(hideFirst == 1){
				printf("\t3. Tento zapas skoncil. Jiz neni mozne si na nej vsadit.\n");
				}
				
				printf("\t4. Zpatky do menu\n");
				
				printf("\n\tZadej volbu: ");
				scanf("%d", &sportMenu);
				
				if(sportMenu == 1 && hideFirst == 1){
					printf("\n\tTento zapas neexistuje!");
					return 0;
				}else if(sportMenu == 2 && hideSecond == 1){
					printf("\n\tTento zapas neexistuje!");
					return 0;
				}else if(sportMenu == 3 && hideThird == 1){
					printf("\n\tTento zapas neexistuje!");
					return 0;					
				}
				
				
				switch(sportMenu){
					
					case 1:
						
						hideFirst++;
						
						printf("\n\tHC Dynamo Pardubice [Kurz 2.33] | Remiza [Kurz 1.88] | HC Sparta Praha [Kurz 3.14]\n");
						printf("\tJaky bude vysledek zapasu? (Pardubice - 1, remiza - 2, Sparta - 3): ");
						scanf("%d", &vysledekPrvni);
						
						if(vysledekPrvni != 1 && vysledekPrvni != 2 && vysledekPrvni != 3){
							printf("\n\t Neplatna moznost!\n");
							return 0;
						}
						
						
						
						printf("\n\tKolik chces vsadit na tento vysledek: ");
						scanf("%f", &sportSazka1);
						
						if(sportSazka1 > balance){
							printf("\n\tNemas dostatek financi.\n");
							return 0;
						}
						
						balance = balance - sportSazka1;
						
						printf("\n\tPrejes si vsadit na presny pocet golu? (Y/N): ");
						scanf(" %c", &rozhodnutiGoly1);
						
						if(rozhodnutiGoly1 == 'y'){
							printf("\n\tKolik golu padne v zapase? (2-9): ");
							scanf("%d", &presnyPocetGolu1);
							
							if(presnyPocetGolu1 < 2 && presnyPocetGolu1 > 9){
								printf("\n\tMuzes zadat pouze 2 az 9!\n");
								return 0;
							}
						
							printf("\n\tKolik chces vsadit na presny pocet golu? ");
							scanf("%d", &sazkaGoly1);
							
						if(sazkaGoly1 > balance){
							printf("\n\tNemas dostatek financi.\n");
							return 0;
						}

						balance = balance - sazkaGoly1;
							
						}else if(rozhodnutiGoly1 != 'y' && rozhodnutiGoly1 != 'n'){
							printf("\n\tNeplatna moznost.\n");
							return 0;
						}
						
						
														generateNumber();
														goalsInMatch = 0 + pocetGolu();
														
														for(s=0; s < goalsInMatch; s++){
															
															sleep(1);
															
															generateNumber();
															mezivypocetGoly = 0 + tymyGoly();
															
															if(mezivypocetGoly < 70){
																printf("\n\tPardubice vstrelily gol!\n");
																prvniGolyT1++;
															}else{
																printf("\n\tSparta vstrelila gol!\n");
																prvniGolyT2++;																
															}
	
														}
														
														printf("\n\tZapas skoncil!\n");
														printf("\n\tVysledek zapasu: [%d:%d]\n", prvniGolyT1, prvniGolyT2);
														
						mezivypocetGoly1 = prvniGolyT1 + prvniGolyT2;
						printf("\n\tV zapase padlo %d golu.\n", mezivypocetGoly1);
						
						if(rozhodnutiGoly1 == 'y' && presnyPocetGolu1 == mezivypocetGoly1){
							printf("\tTva sazka na pocet golu byla vyhodnocena jako vyherni!\n");
							vyhraGoly1 = sazkaGoly1 * 8;
							balance = balance + vyhraGoly1;
							printf("\tS kurzem 8.00 vyhravas %.2f a stav tveho herniho konta je nyni %.2f", vyhraGoly1, balance);
						}else if(rozhodnutiGoly1 == 'y' && presnyPocetGolu1 != mezivypocetGoly1){
							printf("\tTva sazka na pocet golu nebyla vyhodnocena jako vyherni.\n");
						}
						
														
						if(vysledekPrvni == 1 && prvniGolyT1 > prvniGolyT2){
							sleep(1);
							
							sportVyhra1 = sportSazka1 * 2.33;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra1);
						}else if(vysledekPrvni == 2 && prvniGolyT1 == prvniGolyT2){
							sleep(1);
							
							sportVyhra1 = sportSazka1 * 1.88;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra1);
						}else if(vysledekPrvni == 3 && prvniGolyT1 < prvniGolyT2){
							sleep(1);
							
							sportVyhra1 = sportSazka1 * 3.14;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra1);
						}else{
							sleep(1);
							
							printf("\n\tTvuj tiket nebyl vyhodnocen jako vyherni.\n"); 
						}
						
						balance = balance + sportVyhra1;
						printf("\n\t Na ucte mas nyni %.2f dolaru.", balance);
						

					break;
					
					case 2:
						
						
						
						hideSecond++;
						
						printf("\n\tHK Ostrava Poruba [Kurz 1.67] | Remiza [Kurz 4.28] | HK Usti nad Labem [Kurz 8.50]\n");
						printf("\tJaky bude vysledek zapasu? (Ostrava - 1, remiza - 2, Usti nad Labem - 3): ");
						scanf("%d", &vysledekPrvni);
						
						if(vysledekPrvni != 1 && vysledekPrvni != 2 && vysledekPrvni != 3){
							printf("\n\t Neplatna moznost!\n");
							return 0;
						}
						
						
						
						printf("\n\tKolik chces vsadit na tento vysledek: ");
						scanf("%f", &sportSazka2);
						
						if(sportSazka2 > balance){
							printf("\n\tNemas dostatek financi.\n");
							return 0;
						}
						
						balance = balance - sportSazka2;
						
						printf("\n\tPrejes si vsadit na presny pocet golu? (Y/N): ");
						scanf(" %c", &rozhodnutiGoly2);
						
						if(rozhodnutiGoly2 == 'y'){
							printf("\n\tKolik golu padne v zapase? (2-9): ");
							scanf("%d", &presnyPocetGolu2);
							
							if(presnyPocetGolu2 < 2 && presnyPocetGolu2 > 9){
								printf("\n\tMuzes zadat pouze 2 az 9!\n");
								return 0;
							}
							
							printf("\n\tKolik chces vsadit na presny pocet golu? ");
							scanf("%d", &sazkaGoly2);
							
						if(sazkaGoly2 > balance){
							printf("\n\tNemas dostatek financi.\n");
							return 0;
						}
						
						balance = balance - sazkaGoly2;
						
						}else if(rozhodnutiGoly2 != 'y' && rozhodnutiGoly2 != 'n'){
							printf("\n\tNeplatna moznost.\n");
							return 0;
						}
						
														generateNumber();
														goalsInMatch = 0 + pocetGolu();
														
														for(s=0; s < goalsInMatch; s++){
															
															sleep(1);
															
															generateNumber();
															mezivypocetGoly = 0 + tymyGoly();
															
															if(mezivypocetGoly < 90){
																printf("\n\tOstrava vstrelila gol!\n");
																druhyGolyT1++;
															}else{
																printf("\n\tUsti nad Labem vstrelilo gol!\n");
																druhyGolyT2++;																
															}
	
														}
														
														printf("\n\tZapas skoncil!\n");
														printf("\n\tVysledek zapasu: [%d:%d]\n", druhyGolyT1, druhyGolyT2);
										
						mezivypocetGoly2 = druhyGolyT1 + druhyGolyT2;
						printf("\n\tV zapase padlo %d golu.\n", mezivypocetGoly2);
						
						if(rozhodnutiGoly2 == 'y' && presnyPocetGolu2 == mezivypocetGoly2){
							printf("\tTva sazka na pocet golu byla vyhodnocena jako vyherni!\n");
							vyhraGoly2 = sazkaGoly2 * 8;
							balance = balance + vyhraGoly2;
							printf("\tS kurzem 8.00 vyhravas %.2f a stav tveho herniho konta je nyni %.2f", vyhraGoly2, balance);
						}else if(rozhodnutiGoly2 == 'y' && presnyPocetGolu2 != mezivypocetGoly2){
							printf("\tTva sazka na pocet golu nebyla vyhodnocena jako vyherni.\n");
						}
														
						if(vysledekPrvni == 1 && druhyGolyT1 > druhyGolyT2){
							sleep(1);
							
							sportVyhra2 = sportSazka2 * 1.67;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra2);
						}else if(vysledekPrvni == 2 && druhyGolyT1 == druhyGolyT2){
							sleep(1);
							
							sportVyhra2 = sportSazka2 * 4.28;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra2);
						}else if(vysledekPrvni == 3 && druhyGolyT1 < druhyGolyT2){
							sleep(1);
							
							sportVyhra2 = sportSazka2 * 8.50;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra2);
						}else{
							sleep(1);
							
							printf("\n\tTvuj tiket nebyl vyhodnocen jako vyherni.\n");
						}		
					
						balance = balance + sportVyhra2;
						printf("\n\t Na ucte mas nyni %.2f dolaru.", balance);
					
					break;
					
					case 3:

						
						
						 
						hideThird++;
						
						printf("\n\tFC Mexico City [Kurz 1.42] | Remiza [Kurz 1.17] | FC Tijuana [Kurz 1.58]\n");
						printf("\tJaky bude vysledek zapasu? (Mexico City - 1, remiza - 2, Tijuana - 3): ");
						scanf("%d", &vysledekPrvni);
						
						if(vysledekPrvni != 1 && vysledekPrvni != 2 && vysledekPrvni != 3){
							printf("\n\t Neplatna moznost!\n");
							return 0;
						}
						
						
						
						printf("\n\tKolik chces vsadit na tento vysledek: ");
						scanf("%f", &sportSazka3);
						
						
						if(sportSazka2 > balance){
							printf("\n\tNemas dostatek financi.\n");
							return 0;
						}
						
						balance = balance - sportSazka3;
						
						printf("\n\tPrejes si vsadit na presny pocet golu? (Y/N): ");
						scanf(" %c", &rozhodnutiGoly3);
						
						if(rozhodnutiGoly3 == 'y'){
							printf("\n\tKolik golu padne v zapase? (2-9): ");
							scanf("%d", &presnyPocetGolu3);
							
							if(presnyPocetGolu3 < 2 && presnyPocetGolu3 > 9){
								printf("\n\tMuzes zadat pouze 2 az 9!\n");
								return 0;
							}
							
							printf("\n\tKolik chces vsadit na presny pocet golu? ");
							scanf("%d", &sazkaGoly3);
							
						if(sazkaGoly3 > balance){
							printf("\n\tNemas dostatek financi.\n");
							return 0;
						}
						
						balance = balance - sazkaGoly3;
						
						}else if(rozhodnutiGoly3 != 'y' && rozhodnutiGoly3 != 'n'){
							printf("\n\tNeplatna moznost.\n");
							return 0;
						}
						
														generateNumber();
														goalsInMatch = 0 + pocetGolu();
														
														for(s=0; s < goalsInMatch; s++){
															
															sleep(1);
															
															generateNumber();
															mezivypocetGoly = 0 + tymyGoly();
															
															if(mezivypocetGoly < 50){
																printf("\n\tMexico City vstrelilo gol!\n");
																tretiGolyT1++;
															}else{
																printf("\n\tTijuana vstrelila gol!\n");
																tretiGolyT2++;																
															}
	
														}
														
														printf("\n\tZapas skoncil!\n");
														printf("\n\tVysledek zapasu: [%d:%d]\n", tretiGolyT1, tretiGolyT2);
									
						mezivypocetGoly3 = tretiGolyT1 + tretiGolyT2;
						printf("\n\tV zapase padlo %d golu.\n", mezivypocetGoly3);
						
						if(rozhodnutiGoly3 == 'y' && presnyPocetGolu3 == mezivypocetGoly3){
							printf("\tTva sazka na pocet golu byla vyhodnocena jako vyherni!\n");
							vyhraGoly3 = sazkaGoly3 * 8;
							balance = balance + vyhraGoly3;
							printf("\tS kurzem 8.00 vyhravas %.2f a stav tveho herniho konta je nyni %.2f", vyhraGoly3, balance);
						}else if(rozhodnutiGoly3 == 'y' && presnyPocetGolu2 != mezivypocetGoly3){
							printf("\tTva sazka na pocet golu nebyla vyhodnocena jako vyherni.\n");
						}	
													
						if(vysledekPrvni == 1 && tretiGolyT1 > tretiGolyT2){
							sleep(1);
							
							sportVyhra3 = sportSazka3 * 1.42;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra3);
						}else if(vysledekPrvni == 2 && tretiGolyT1 == tretiGolyT2){
							sleep(1);
							
							sportVyhra3 = sportSazka3 * 1.17;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra3);
						}else if(vysledekPrvni == 3 && tretiGolyT1 < tretiGolyT2){
							sleep(1);
							
							sportVyhra3 = sportSazka3 * 1.58;
							printf("\n\tTvuj tiket byl vyhodnocen jako vyherni!\n");
							printf("\tVyhravas %.2f dolaru.\n", sportVyhra3);
						}else{
							sleep(1);
							
							printf("\n\tTvuj tiket nebyl vyhodnocen jako vyherni.\n");
						}
					
						balance = balance + sportVyhra3;
						printf("\n\t Na ucte mas nyni %.2f dolaru.", balance);
						
					break;
				}
				
			
				
			}while(sportMenu != 4);
			
			
		break;
		
		
		case 6:
			
			printf("\n");
			printf("\tStav herniho konta je %.2f dolaru.\n", balance);
			printf("\n");
			printf("\t");
			system("PAUSE");
			system("cls");
		break;	
		
																												
		case 7:	
		printf("\n");
    printf("\t  _______      _      _                                            \n");
    printf("\t |__   __|    | |    (_)                                           \n");
    printf("\t    | |  ___  | |__   _  ___ __      __ __ _   __ _   __ _  _   _  \n");
    printf("\t    | | / _ \\ | '_ \\ | |/ __|\\ \\ /\\ / // _` | / _` | / _` || | | | \n");
    printf("\t    | || (_) || |_) || |\\__ \\ \\ V  V /| (_| || (_| || (_| || |_| | \n");
    printf("\t    |_| \\___/|_.__/ |_|\\___/  \\_/\\_/  \\__,_| \\__, | \\__, | \\__, | \n");
    printf("\t  ___    ___  ___   _  _                       __/ |  __/ |  __/ | \n");
    printf("\t |__ \\  / _ \\|__ \\ | || |                     |___/  |___/  |___/  \n");
    printf("\t    ) || | | |  ) || || |_                                         \n");
    printf("\t   / / | | | | / / |__   _|                                        \n");
    printf("\t  / /_ | |_| |/ /_    | |                                          \n");
    printf("\t |____| \\___/|____|   |_|                                          \n");
    printf("\t                                                                    \n");
    printf("                                                                    \n");
                                             
		printf("\t");
		system("PAUSE");
		system("cls");

		break;																		

	}
	
}while(decisionMenu != 8);

	printf("\t");
    system("PAUSE");
}
