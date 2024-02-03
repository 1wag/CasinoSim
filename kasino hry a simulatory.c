
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <time.h>
	#include <math.h>
	#include <string.h>
	#include <windows.h>

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

int returnRoulette(){
	return rand() % 36 + 1;
}

int returnBlackjack(){
	return rand() % 10 + 1;
}

int returnDice(){
	return rand() % 6 + 1;
}

int returnSlot(){
	return rand() % 9 + 1;
}

int main(){
	
	// casino variables
	
	int balance = 1000;
	
	// coinflip variables
	
		unsigned long long i;	
		unsigned long long random;
	
		unsigned long long heads = 0; //panna
		unsigned long long tails = 0; //orel
		
		int decisionCount;
		char decisionShow;
		
	// blackjack variables
	
		int playerHand = 0;
		int dealerHand = 0;
	
		int playerCard;
		int dealerCard;
			
		int playerBalance = 1000;
		int playerBet;

    	int standHit; // stand 0, hit 1
    	int dobleSplit; // double 0, split 1
		
	// roulette variables
	
		//economy
			int rouletteBet;
			int rouletteWin;
			int step;

			int rouletteActual;
			
		//bets
			int rouletteGuess;
			char redOrBlack;
			char oddOrEven;
			int numThroughNum;
			int pairTwelve;
			int doubleZero;
						
		//dowhile
			int rouletteMenu;
			int skip;
			
	// dice variables
		
			int diceRoll;
			int diceGuess;
			
			int diceSimulator;
			char diceDecision;
			
			unsigned long long diceOnes = 0;
			unsigned long long diceTwos = 0;
			unsigned long long diceThrees = 0;
			unsigned long long diceFours = 0;
			unsigned long long diceFives = 0;
			unsigned long long diceSixes = 0;
			
			int diceMenu;
			
	// slot machine variables
	
			int slotOne;
			int slotTwo;
			int slotThree;
			
		//economy
		
			int slotBet;
			int slotWin;
			
			int slotMenu;
			
	// menu variables
			int decisionMenu;
	
	printf("\n");
	
	printf("\tVersion 1.02 | Last updated 3/2/2024 | Project by Tobiswaggy\n");
	printf("\tThis program is currently in beta. Many features still do not work as intended...\n");
	
	printf("\n");
	
	printf("\tCasino games & math simulators.\n"); 
	printf("\t1. Coinflip simulator\n");
	printf("\t2. Blackjack\n");
	printf("\t3. Roulette table\n");
	printf("\t4. Dice\n");
	printf("\t5. Slot machine\n");
	printf("\t6. Rules and probability (english)\n");
	printf("\t7. Pravidla a pravdepodobnost (cesky)\n");
	printf("\t8. Check balance\n");
	printf("\t9. Settings\n");
	printf("\t10. Credits\n");
	printf("\t11. Exit the program\n");
	
	do{
	
	printf("\n\tWhich option do you choose? ");
	scanf("%d", &decisionMenu);
	
	
	switch(decisionMenu){
		
																				case 1: // hod minci
				
		// program dokaze hodit minci 18446744073709551615 krat
	
	printf("Coinflip simulator\n");
	
	printf("How many coinflips do you want to simulate? ");
	scanf("%d", &decisionCount);
	
	
	if(decisionCount <= 0){
		printf("A coin must be flipped atleast once!");
		return 0;
	}
	
	printf("Warning! Outputting a large amount of coinflips may take a long time!\n");
	printf("Do you want to see every single coinflip made? (Y/N): ");
	scanf(" %c", &decisionShow);
	
	
	if(decisionShow != 'y' && decisionShow != 'Y' && decisionShow != 'n' && decisionShow != 'N'){
		printf("You have to answer with either Y or N!");
		return 0;
	}
	
	for(i = 1; i <= decisionCount; i++){
		
		generateNumber();
		random = returnCoinflip();
		
		if(random == 0){
			
			if(decisionShow == 'y' || decisionShow == 'Y'){
			printf("Coinflip number %d - Heads\n", i);
			}
			
			heads++;
			
		}else if(random == 1){
			
			if(decisionShow == 'y' || decisionShow == 'Y'){
			printf("Coinflip number %d - Tails\n", i);
			}
			
			tails++;
		}
			
	}
	
	printf("\n");
	
	printf("The coin has been flipped a total of %d times.\n", decisionCount);

	printf("\n");
	
	printf("Heads: %d\n", heads);
	printf("Tails: %d", tails);
	
	printf("\n");
		
		float ratioHeads = ((float)heads / decisionCount) * 100;
		float ratioTails = ((float)tails / decisionCount) * 100;
		
	printf("Percentage ratio: ");
	printf("%.2f%% | ", ratioHeads);
	printf("%.2f%%", ratioTails);
	
	printf("\n");
	printf("\n");	
				
		break;
		
																							case 2: // blackjack
			
			printf("We currently have only about 100 lines of code for blackjack...\n");
			printf("This game is currently being reworked\n");
			
			/*
			
printf("Vitej v aplikaci Blackjack. Projekt vytvoril Tobiswaggy.\n", 1);
	
	// dev note: variables jsou v anglictine protoze anglicky to zni lip
	// stay mad
			
	printf("\n");
	
	printf("Zadej sazku: ");
	
		scanf("%d", &playerBet);
	
	if(playerBet > playerBalance){
		
		printf("Nemas dostatecne finance");
		
		return 0;
	}
	
	printf("\n");
	
	printf("Startuji hru.\n");
	
	printf("\n");

/* JE TO V HAJZLU - OPRAVIT PROMENNY A NAMRDAT TO DO PODPROGRAMU

	generateNumber();
		playerCard1 = 0 + returnBlackjack();
	
	// mezivypocet
		playerHand2 = playerCard + playerCard;
	
	generateNumber();
		dealerCard1 = 0 + retur1nNumber();   2
	
	generateNumber();
		dealerCard2 = 0 + returnNumber();	
	
	// mezivypocet
		dealerHand = dealerCard1 + dealerCard2;
	
	printf("Vase prvni karta je %d\n", playerCard1);
	
		printf("Vase druha karta je %d\n", playerCard2);
		
			printf("Soucet vasich karet cini %d\n", playerHand);
	
	printf("Dealerova prvni karta je %d\n", dealerCard1);
	
		printf("Dealerova druha karta je skryta.\n");
	
	printf("Hit (1) / stand (0): \n");
		scanf("%d", &standHit);
	
	
	// toto cely musi jit do hajzlu - rework do podprogramu
	
/*	
	if(standHit == 0){
		
		printf("Stand!\n");
		
		printf("Dealerova skryta odkryta: %d\n", dealerCard2);
		
		printf("Soucet dealerovych karet je %d\n", dealerHand);
		
		if(dealerHand < playerHand){
			
			generateNumber();
			dealerCard3 = 0 + returnNumber();
			printf("Dealerova treti karta je %d\n", dealerCard3);
			
			dealerHand = dealerHand + dealerCard3;
			
			printf("Dealer ma %d!", dealerHand);
						
			if(dealerHand < playerHand){
			generateNumber();
			dealerCard4 = 0 + returnNumber();
			printf("Dealerova ctvrta karta je %d\n", dealerCard4);
			
			dealerHand = dealerHand + dealerCard4;
			
			printf("Dealer ma %d!", dealerHand);		
			}
		}
	}
*/
		
																							break;
		
																							case 3: // ruleta
			
			// cerna cisla: 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35
						
			do{
			
			skip = 0;
			
			printf("Roulette table.\n");
			printf("1. Bet on an exact number\n");
			printf("2. Bet on either red or black\n");
			printf("3. Bet on either odd or even\n");
			printf("4. 1 through 18 | 19 through 36\n");
			printf("5. 1st twelve | 2nd twelve | 3rd twelve\n");
			printf("6. Exit program\n");
			
			printf("Which option do you choose? ");
			scanf("%d", &rouletteMenu);
			
			switch(rouletteMenu){
				
				case 1:
					
					printf("Which number do you choose? (0-36) ");
					scanf("%d", &rouletteGuess);
					
					if(rouletteGuess > 36 || rouletteGuess < 0){
						printf("This number does not exist.");
						return 0;
					}
					
				break;
				
				case 2:
					
					printf("Do you wanna bet on red or black? (R/B): ");
					scanf(" %c", &redOrBlack);
					
					if(redOrBlack != 'r' && redOrBlack != 'R' && redOrBlack != 'b' && redOrBlack != 'B'){
						printf("This color does not exist.");
						return 0;
					}
					
				break;
				
				case 3:
					
					printf("Do you wanna bet on odd or even? (O/E): ");
					scanf(" %c", &oddOrEven);
					
					if(oddOrEven != 'o' && oddOrEven != 'O' && oddOrEven != 'e' && oddOrEven != 'E'){
						printf("This option is invalid.");
						return 0;
					}
					
				break;
				
				case 4:
					
					printf("1 through 18 or 19 through 36? (1/2): ");
					scanf("%d", &numThroughNum);
					
					if(numThroughNum != 1 && numThroughNum != 2){
						printf("This option is invalid.");
						return 0;
					}
					
				break;
				
				case 5:
					
					printf("1st twelve or 2nd twelve or 3rd twelve? (1/2/3): ");
					scanf("%d", &pairTwelve);
					
					if(pairTwelve != 1 && pairTwelve != 2 && pairTwelve != 3){
						printf("This option is invalid.");
						return 0;
					}
					
				break;
				
				case 6:
					
					printf("Quiting...\n");
					return 0;
					
				break;
						
			}
			
			printf("Your balance is %d\n", balance);
			
			printf("Place your bet: ");
			scanf("%d", &rouletteBet);
			
			if(rouletteBet > balance){
				printf("Insufficient balance.");
				return 0;
			}
			
			balance = balance - rouletteBet;
			
			generateNumber();
			rouletteActual = returnRoulette();
			
			printf("Number %d has been rolled!\n", rouletteActual);
			
			if(rouletteGuess == rouletteActual){
				printf("Straight up.\n");
				
				rouletteWin = rouletteBet * 35;
				
				printf("You win %d $"), rouletteWin;
				
				skip++;
			}

// jsem linej hajzl, nechtelo se mi na tohle delat podprogram
// source: chatgpt ↓

if ((redOrBlack == 'r' && redOrBlack == 'R') && 
        (rouletteActual == 1 || rouletteActual == 3 || rouletteActual == 5 || 
         rouletteActual == 7 || rouletteActual == 9 || rouletteActual == 12 || 
         rouletteActual == 14 || rouletteActual == 16 || rouletteActual == 18 || 
         rouletteActual == 19 || rouletteActual == 21 || rouletteActual == 23 || 
         rouletteActual == 25 || rouletteActual == 27 || rouletteActual == 30 || 
         rouletteActual == 32 || rouletteActual == 34 || rouletteActual == 36)) {
         	
  				printf("Red number!\n");
  				
				rouletteWin = rouletteBet * 2;
				
  				printf("You win %d$\n", rouletteWin);
  				
  				skip++;
  				
}else if ((redOrBlack == 'b' && redOrBlack == 'B') && 
        (rouletteActual == 2 || rouletteActual == 4 || rouletteActual == 6 || 
         rouletteActual == 8 || rouletteActual == 10 || rouletteActual == 11 || 
         rouletteActual == 13 || rouletteActual == 15 || rouletteActual == 17 || 
         rouletteActual == 20 || rouletteActual == 22 || rouletteActual == 24 || 
         rouletteActual == 26 || rouletteActual == 28 || rouletteActual == 29 || 
         rouletteActual == 31 || rouletteActual == 33 || rouletteActual == 35)) {
         	
  				printf("Black number!\n");
  			
				rouletteWin = rouletteBet * 2;
  			
  				printf("You win %d$\n", rouletteWin);
			  
			  skip++;
}

    if ((oddOrEven == 'o' && oddOrEven == 'O') && rouletteActual % 2 != 0) {
    	
		printf("Odd number!\n");
		
				rouletteWin = rouletteBet * 2;
		
		printf("You win %d$\n", rouletteWin);
        
        skip++;
        
    } else if ((oddOrEven == 'e' && oddOrEven == 'E') && rouletteActual % 2 == 0) {
  
		printf("Even number!\n");
		
				rouletteWin = rouletteBet * 2;
		
		printf("You win %d$\n", rouletteWin); 	
       
       	skip++;
    } 
	
	
	if(numThroughNum == 1 && rouletteActual >= 1 && rouletteActual <= 18){
		
		printf("1 through 18!\n");
		
				rouletteWin = rouletteBet * 2;
		
		printf("You win %d$\n", rouletteWin);
		
		skip++;
		
	}else if(numThroughNum == 2 && rouletteActual >= 19 && rouletteActual <= 36){
		
		printf("19 through 36!\n");
		
						rouletteWin = rouletteBet * 2;
						
		printf("You win %d$\n", rouletteWin);
		
		skip++;
		
	}
	
if(pairTwelve == 1 && rouletteActual >= 1 && rouletteActual <= 12){
	
	printf("First twelve!\n");
	
					rouletteWin = rouletteBet * (rouletteBet * 2);
					
	printf("You win %d$\n", rouletteWin);
	
	skip++;
}
else if(pairTwelve == 2 && rouletteActual >= 13 && rouletteActual <= 24){
	
	printf("Second twelve!\n");
	
						rouletteWin = rouletteBet * (rouletteBet * 2);
						
	printf("You win %d$\n", rouletteWin);
	
	skip++;
}
else if(pairTwelve == 3 && rouletteActual >= 25 && rouletteActual <= 36){
	
	printf("Third twelve!\n");
	
						rouletteWin = rouletteBet * (rouletteBet * 2);
						
	printf("You win %d$\n", rouletteWin);
	
	skip++;
}

if(skip == 0){
	printf("You lose.\n");
}
			
}while(rouletteMenu != 7);

		
		break;
		
																								case 4: // hod kostkou
		
			printf("Dice roll\n");
			
			printf("1. Dice gambling\n");
			printf("2. Dice simulator\n");
			printf("3. Exit program\n");
			
			printf("Enter your option: ");
			scanf("%d", &diceMenu);
			
			if(diceMenu != 1 && diceMenu != 2 && diceMenu != 3){
				printf("This is not a valid option!\n");
				return 0;
			}
			
			do{
				switch(diceMenu){
					
					case 1:
						
					break;
					
					case 2:
						
						printf("How many times do you want to roll the dice? ");
						scanf("%d", &diceSimulator);
						
						printf("Warning: Displaying a huge amount of rolls may take a long time!\n");
						
						printf("Do you want to display each roll? (Y/N): ");
						scanf(" %c", &diceDecision);
						
						if(diceDecision != 'y' && diceDecision != 'Y' && diceDecision != 'n' && diceDecision != 'M'){
							printf("This is not a valid option!\n");
							return 0;
						}
						
						for(i=0; i <= diceSimulator; i++){
							
							generateNumber();
							diceRoll = returnDice();
							
							if(diceDecision == 'y' && diceDecision == 'Y'){
								printf("Dice roll number %d: %d\n", i, diceRoll);
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
						
						printf("A total of %d dices have been rolled.\n", i);
						
						printf("Ones: %d\n", diceOnes);
						printf("Twos: %d\n", diceTwos);
						printf("Threes: %d\n", diceThrees);
						printf("Fours: %d\n", diceFours);
						printf("Fives: %d\n", diceFives);
						printf("Sixes: %d\n", diceSixes);						
						
					break;
					
					case 3:
						
						printf("Quitting...\n");
						return 0;
						
					break;
					
				}
			}while(diceMenu != 3);
			
			/* generateNumber();
			returnDice(); */
			
		break;
			
																case 5: // automat
		
			printf("Slot machine\n");
			printf("Rules:\n");
			printf("One seven - 1.5x payout\n");
			printf("Two sevens - 8x payout\n");
			printf("Three sevens - 50x payout\n");
			printf("\n");
			printf("2 same numbers - 3x payout\n");
			printf("3 same numbers - 50x payout\n");
			printf("\n");
			
			do{
				
				printf("Place a bet: ");
				scanf("%d", &slotBet);
				
				generateNumber();
				slotOne = returnSlot();
				
				generateNumber();
				slotTwo = returnSlot();
				
				generateNumber();
				slotThree = returnSlot();
				
				for(i=0; i<10; i++){
					printf("Spinning.\n");
				}
				
				if(slotOne == 7 || slotTwo == 7 || slotThree == 7){
					slotWin = slotBet * 1.5;
					printf("1.5x payout. You win %d$\n", slotWin);
				}else if(slotOne == 7 && slotTwo == 7){
					slotWin = slotBet * 8;
					printf("8x payout. You win %d$\n", slotWin);
				}else if(slotTwo == 7 && slotThree == 7){
					slotWin = slotBet * 8;
					printf("8x payout. You win %d$\n", slotWin);
				}else if(slotOne == 7 && slotThree == 7){
					slotWin = slotBet * 8;
					printf("8x payout. You win %d$\n", slotWin);
				}else if(slotOne == 7 && slotTwo == 7 && slotThree == 7){
					slotWin = slotBet * 50;
					printf("Jackpot! You win %d$\n", slotWin);
					
				}else if(slotOne == slotTwo || slotTwo == slotThree || slotOne == slotThree){
					slotWin = slotBet * 3;
					printf("3x payout. You win %d$\n", slotWin);
				}else if(slotOne == slotTwo && slotTwo == slotThree && slotOne == slotThree){
					slotWin = slotBet * 50;
					printf("Jackpot! You win %d$\n", slotWin);
				}
				
				printf("%d | %d | %d\n", slotOne, slotTwo, slotThree);
				
				printf("Type 1 to roll again. Type 0 to stop: \n");
				scanf("%d", &slotMenu);
								
			}while(slotMenu != 0);
			
		break;
		
		case 6: // otevre separatni textovej soubor ve slozce (anglicky preklad)
		
			system ("rules.html");
			 // https://stackoverflow.com/questions/17417718/how-to-open-a-text-file-in-notepad-in-a-c-program
		
		break;	
		
		case 7:
		
			system("pravidla.html");
			
		break;
		
		case 8:
			
			printf("Your balance is %d$\n", balance);
			
		break;
		
		case 9:
			
			printf("Coming soon...\n");
			
		break;
		
		case 10:
			
			system("credits.bat");
			system("popups.vbs");
					
		break;			
		
		case 11: // ukonceni programu
		
						printf("Quitting...\n");
			return 0;
				
		break;
		
	}
	
}while(decisionMenu != 11);

	
    system("PAUSE");
}