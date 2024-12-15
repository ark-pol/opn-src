//Author Arkadiusz Kiciak
//Poland - 15.12.2024
//Opensource - share freely

//Example usage:
//prog.exe GD1G ???????? 9
//prog.exe GD1G ???????0 9
//prog.exe GD1G 000????0 9

#include <stdio.h>

#define exitPoint(HINT) \
if(HINT != 0) { printf("\n\n%s",HINT);} \
puts("\n\nThank you. Press any key ..."); \
fflush(stdin); getch(); return 0;

int main(int argc, char *argv[]){

	int sumAllItems, definedSum, currentSum;

	int currentItemValue, multiplayBy;
	
	int externalCounter, internalCounter;

	int lengthOfArg, processAll;
	
	char counterTable[8][2] = {0,0};
	
	if(argc!=4){
		
		exitPoint("Missing starting parameters. Example usage: prog.exe GD1G ???????0 9");
	
	}
	
	lengthOfArg = strlen(argv[1]);
			
	if(lengthOfArg!=4){
    	
		exitPoint("Wrong first parameter (wykaz sadowy)! Should have 4 capital characters!");
    
	} else {
		
        printf("\n\nUsing (wykaz sadowy) as: '%s'",argv[1]);
                              
        sumAllItems = 0; currentItemValue = 0; multiplayBy = 0;
                                                    
        for(internalCounter=0;internalCounter<strlen(argv[1]);internalCounter++){
            
            //character is in range 0-9
            if(argv[1][internalCounter]>='0' && argv[1][internalCounter]<='9'){

				//simple conversion asci character to digit
				currentItemValue = argv[1][internalCounter] - '0';
            
			//checking the rest for character is in range        
			} else {
			
				switch(argv[1][internalCounter]){
	                
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':

						currentItemValue = argv[1][internalCounter] - 54;

	                    break;                    
					
					//case 'Q';//decreasing 1
					case 'R':
					case 'S':
					case 'T':
					case 'U':

						currentItemValue = argv[1][internalCounter] - 55;

	                    break;                    
						
					//case 'V';//decreasing 2
					case 'W':

						currentItemValue = argv[1][internalCounter] - 56;

	                    break;                    
						
					case 'X':
						
						currentItemValue = 10;
						
						break;
					
					//becoude case 'V';//decreasing 3
					case 'Y':
	                case 'Z':
					    
						currentItemValue = argv[1][internalCounter] - 57;
	                    
						break;                    
											                   
	                default:
						
	                    printf("\n\nNot permitted character: '%c'",argv[1][internalCounter]);
	                    
						exitPoint("Used not permitted character in (wykaz sadowy).");
						
						break;
	        
				}
				    
			}
			                
			switch(internalCounter){
								
				case 0:
				case 3:
					multiplayBy = 1;
					break;
				case 1:
					multiplayBy = 3;
					break;
				case 2:
					multiplayBy = 7;	
					break;
			
			}
			
			sumAllItems += currentItemValue*multiplayBy;
											
		}//end for loop checking wykaz sadowy
						
		lengthOfArg = strlen(argv[2]);
		
		if(lengthOfArg!=8){
			
			exitPoint("\n\nPettern for (ksiega wieczysta) should have 8 digit or special character like '?'.");
			
		}
		
		for(internalCounter=0;internalCounter<lengthOfArg;internalCounter++){
		
			//checking we have digit from rage 0-9	
			if(argv[2][internalCounter]>='0' && argv[2][internalCounter]<='9'){
							
				counterTable[lengthOfArg-internalCounter-1][0] =
					argv[2][internalCounter] - '0';
				
				counterTable[lengthOfArg-internalCounter-1][1] =
					argv[2][internalCounter] - '0';
					
			} else if(argv[2][internalCounter]=='?'){
			
				counterTable[lengthOfArg-internalCounter-1][0] = -1;
				counterTable[lengthOfArg-internalCounter-1][1] = 0;
				
			} else {
				
				printf("\n\nNot permitted character: '%c'",argv[2][internalCounter]);
	                    
				exitPoint("Used not permitted character in (ksiega wieczysta).");	
				
			}
			
		}
		
		printf("\n\nUsing specified (ksiega wieczysta): '%s' as: '%c%c%c%c%c%c%c%c'",
			argv[2],
			(counterTable[7][0]==-1) ? '?' : counterTable[7][0]+'0',
			(counterTable[6][0]==-1) ? '?' : counterTable[6][0]+'0',
			(counterTable[5][0]==-1) ? '?' : counterTable[5][0]+'0',
			(counterTable[4][0]==-1) ? '?' : counterTable[4][0]+'0',
			(counterTable[3][0]==-1) ? '?' : counterTable[3][0]+'0',
			(counterTable[2][0]==-1) ? '?' : counterTable[2][0]+'0',
			(counterTable[1][0]==-1) ? '?' : counterTable[1][0]+'0',
			(counterTable[0][0]==-1) ? '?' : counterTable[0][0]+'0');					
			
		processAll = !((counterTable[7][0]!=-1)||(counterTable[6][0]!=-1)||
			(counterTable[5][0]!=-1)||(counterTable[4][0]!=-1)||
			(counterTable[3][0]!=-1)||(counterTable[2][0]!=-1)||
			(counterTable[1][0]!=-1)||(counterTable[0][0]!=-1));
					
		definedSum = atoi(argv[3]);
		
		if(definedSum<0||definedSum>9){
			
			exitPoint("\n\nDefined wrong value for (suma kontrolna). Perrmited range is 0-9.");	
			
		}
		
		printf("\n\nUsing specified (suma kontrolna) as: %i\n",definedSum);
		
		//8 digit processing - 8 loop
		for(counterTable[7][1]=0;counterTable[7][1]<10;counterTable[7][1]++)
		for(counterTable[6][1]=0;counterTable[6][1]<10;counterTable[6][1]++)
		for(counterTable[5][1]=0;counterTable[5][1]<10;counterTable[5][1]++)
		for(counterTable[4][1]=0;counterTable[4][1]<10;counterTable[4][1]++)
		for(counterTable[3][1]=0;counterTable[3][1]<10;counterTable[3][1]++)
		for(counterTable[2][1]=0;counterTable[2][1]<10;counterTable[2][1]++)
		for(counterTable[1][1]=0;counterTable[1][1]<10;counterTable[1][1]++)
		for(counterTable[0][1]=0;counterTable[0][1]<10;counterTable[0][1]++){
			
			if(((counterTable[0][0]==-1)?1:(counterTable[0][0]==counterTable[0][1]))&&
			((counterTable[1][0]==-1)?1:(counterTable[1][0]==counterTable[1][1]))&&
			((counterTable[2][0]==-1)?1:(counterTable[2][0]==counterTable[2][1]))&&
			((counterTable[3][0]==-1)?1:(counterTable[3][0]==counterTable[3][1]))&&
			((counterTable[4][0]==-1)?1:(counterTable[4][0]==counterTable[4][1]))&&
			((counterTable[5][0]==-1)?1:(counterTable[5][0]==counterTable[5][1]))&&
			((counterTable[6][0]==-1)?1:(counterTable[6][0]==counterTable[6][1]))&&
			((counterTable[7][0]==-1)?1:(counterTable[7][0]==counterTable[7][1]))){ 
			
				currentSum = sumAllItems;
				
				currentSum += counterTable[7][1]*3; currentSum += counterTable[6][1]*7;
				currentSum += counterTable[5][1]*1; currentSum += counterTable[4][1]*3;
				currentSum += counterTable[3][1]*7; currentSum += counterTable[2][1]*1;
				currentSum += counterTable[1][1]*3; currentSum += counterTable[0][1]*7;

				//if suma kontrolna is equial printing matching row				
				if(currentSum%10 == definedSum)
				
				printf("\n%d%d%d%d%d%d%d%d",
					counterTable[7][1],counterTable[6][1],counterTable[5][1],
					counterTable[4][1],counterTable[3][1],counterTable[2][1],
					counterTable[1][1],counterTable[0][1]);
				
					if(!processAll) break;
		
			}	
									
		}
		
		exitPoint(0);
		
	}

}
