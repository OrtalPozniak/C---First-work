/* ==================================================================
	Student name:
	Ortal Pozniak (ID: 203702071)
    Department of Materials Engineering
  =================================================================== */
#include <stdio.h>

int menu,num1,num2,i,j,x,y,k,temp1,temp2,temp3,num_of_digits,end_of_column,flag,flag2,basis_gadol=0,input;
int num_of_mistakes=0,last_row,start,end,counter,y0,spaces,row=0,basis=0,triangle,a,b,c=0,d=0,revach=0;
int end_of_O_column,add,number,temp,tempo,number2;

void main(){
	
	printf ("Welcome, please choose one of the options below:\n");
	printf ("1. Exit.\n");
	printf ("2. Print menu again.\n");
	printf ("3. Rotate a number.\n");
	printf ("4. Sort list of numbers.\n");
	printf ("5. Fibonacci count matrix.\n");
	printf ("6. Print Shield of david.\n");

	do{ //Starting a do while loop, so the user could keep choosing options.

	printf ("Enter your choice:");
	scanf ("%d",&menu);
	
	if((menu<1)||(menu>6))
		num_of_mistakes++; //counting the amount of mistakes the user made in choosing the options from the menu.


	if (menu==1){
		printf ("bye bye!!!\n");
		num_of_mistakes=5; //Promoting the number of mistakes to five, in order to brake the do-while loop and exit the program.
	}
	if (menu==2){
		printf ("Welcome, please choose one of the options below:\n");
		printf ("1. Exit.\n");
		printf ("2. Print menu again.\n");
		printf ("3. Rotate a number.\n");
		printf ("4. Sort list of numbers.\n");
		printf ("5. Fibonacci count matrix.\n");
		printf ("6. Print Shield of david.\n");
	}
	if (menu==3){
		num_of_digits=1;
		printf ("Please enter a number (1-9 digits):");

		scanf ("%d",&num1);
		while(num1>999999999) //Keep giving the user options to insert the right input.
		{
			printf ("Wrong input, try again.\nPlease enter a number (1-9 digits):");
			scanf ("%d",&num1);
		}

		printf ("Please enter a number between -10 to 10:");
		scanf ("%d",&num2);

		while((num2<-10)||(num2>10)) //Keep giving the user options to insert the right input.
		{
			printf ("Wrong input, try again.\nPlease enter a number between -10 to 10:");
			scanf ("%d",&num2);
		}

		temp3=num1;

		while (temp3){ //until we get to the most significant digit.
			temp3=temp3/10; //Each iteration we reduce the least significant digit.
			num_of_digits= num_of_digits*10; 
		}
		num_of_digits= num_of_digits/10; //The last iteration in the while loop was an unnecessary multiply by 10.

		input=num1;

		if (num2>0){ //if the user asked for a rotation to the right.
			for(i=0; i<num2;i++)
			{ //We want to separate the whole number from it's least significant digit.
				temp1=num1/10; 
				temp2=num1%10;
				num1=temp2*num_of_digits+temp1; //That way we could take the least significant digit and put it as the most significant digit.
			}
		}
		else if(num2<0){ //if the user asked for a rotation to the left.

			for (i=0;i>num2;i--){ //We want to separate the whole number from it's most significant digit.
				temp1=num1/num_of_digits;
				temp2=num1%num_of_digits;
				num1=(temp2*10) +temp1; //That way we could take the most significant digit and put it as the least significant digit.
			}

		}

		printf ("The number %d after %d rotation is: %d\n",input,num2,num1);
	}
	if (menu==4){
		printf ("Please enter 2 positive numbers (1-99999) n1,n2 (n1<=n2):");
		scanf ("%d %d",&num1,&num2);

		while(num2<num1) 
		{
			printf ("Wrong input, try again.\nPlease enter 2 positive numbers (1-99999) n1,n2 (n1<=n2):");
			scanf ("%d %d",&num1,&num2);
		}

		printf("Sort list of numbers from %d to %d:\n",num1,num2);

		for (i=num1; i<=num2; i++){
			temp1=i;
			while(temp1) //check the number for all of it's digits
			{
				temp3=temp1%10;
				temp1=temp1/10;
				temp2=temp1%10;
				if(temp2>=temp3) //break if the number doesn't really going up
					break;
			}
			if(temp1==0) //print the number only if it passed the whole while loop
				printf("%d \n",i);
		}
	}
	if (menu==5){
		
		printf ("Please enter 2 positive numbers (1-99999):");
		scanf("%d %d",&x,&y);

		while((x<1)||(x>99999)||(y<1)||(y>99999))
		{
			printf ("Wrong input, try again.\nPlease enter 2 positive numbers (1-99999):");
			scanf("%d %d",&x,&y);
		}
		
		for(i=0;i<11;i++) //Providing 11 rows.
		{
			for(j=0;j<10;j++) //Providing 10 columns.
			{
				if((i==0)&&(j==0)) //The first index (0,0) needs to be an empty space.
					printf("\t");

				else if(i==0) //The first row has only the values of first input and the next following 8 numbers.
					printf("%5d\t",x+j-1);
				
				else if(j==0)//The first column has only the values of second input and the next following 9 numbers.
					printf("%5d\t", y+i-1);	
			
				else
				{
					
			//In each cell of the matrix we have to know what is bigger between the column value and the row value.
					if((x+j-1)>=(y+i-1))
					{
						start=y+i-1; //Determine the lowest number.
						end= x+j-1; //Determine the highest number.
					}
					else
					{
						start=x+j-1; //Determine the lowest number.
						end=y+i-1; //Determine the highest number.
					}
					
					//Intializing the counter of the amount of numbers in the Fibonacci serial in a specific range.
					counter=0;

					if(start==1)
						counter++; //We don't want to loost the first '1' in the Fibonacci serial.

					temp1=0;temp2=1;

					while((temp2<=end))
					{
						temp3= temp2+temp1;
						temp2= temp2+temp3;
						temp1= temp3;//Remember the last value in the serial as the first for the next iteration.

						//Increase the counter if the first number in this iteration is in the range.
						if(((temp3>=start)&&(temp3<=end)))
							counter++;
						//Increase the counter if the second number in this iteration is in the range.
						if((temp2>=start)&&(temp2<=end))
							counter++;

					}
				
				printf("%5d\t",counter);

				}
				
			}
			
			printf("\n");//The end of a specific row.
			
		}
		
	}



	if (menu==6)
	{
	printf ("Please enter a multiple of 3 number between 9 to 54 (9,12,15,...):");
	scanf ("%d",&num1);
	while (((num1%3)!=0)||(num1<9)||(num1>54))
	{
		printf ("Wrong input, try again.\nPlease enter a multiple of 3 number between 9 to 54 (9,12,15,...):");
		scanf ("%d",&num1);

	}
		y0=((2*num1)/3); //The main column of the shield and the high of the zero triangle.
		spaces= y0 +((num1/3)-3)/4; //Initializing the number of spaces needed for the first row.

		if(num1%2) // Separate between two cases, even and odd numbers.
		{
			
			triangle=((num1+1)/4);//the last row that has only zeros
		}
		else
		{	
			if(num1%4) /*If the number is even we have two different cases,
					   when it can divided by 4 and when it's not.*/

				triangle=(num1+2)/4;

			else
			{
					triangle=num1/4;

			}
		
		}
	revach=0;c=0;end_of_O_column=1; //Intializing the counters before entering the loop.
	
	printf("\n");
	while(spaces>=0)
	{
		if((row<triangle)|| (revach> spaces)) /*Print spaces only in the upper
											triangle and after printing the mark '*' */
		{
				for(j=0;j<spaces;j++)
					printf(" ");
	
		}
		else
		{
			d=0; //Intializing the counter before each iteration.
			if((row>triangle-1) &&(revach<=spaces))
			{
				while(d<revach) //Printing all the spaces that we need before the mark '*' for this line.
				{
					printf(" ");
					d++;
				}
					
					while(d<spaces) //Printing all the marks '*' for this specipic line.
					{
						printf("*");
						d++;
					}
					
					if(revach==0)
						end_of_column=d; /*We want to save the number of '*' marks in this line so we know how much we need to print in the 
												right triangle of '*'*/
			}
			
		}
		

		for(k=0;k<end_of_O_column;k++) //Start printing as much 'O' as needed for this line.
		{
			printf("O");
			if(row==triangle-1) /*In this row we want to count the number of the mark 'O' in order to know the
								number of '*' marks for the base of the bottom triangle.*/
				basis++;
			if(row==y0)
				basis_gadol++; /*This is the last row of the 'O' triangle,and we want to know the amount of the mark 'O' in this line
									in order to be able to place the bottom triangle in the middle of the 'O' triangle.*/
			
		}		

	

		if((row>triangle-1)&&(revach<spaces)) //This is the range of rows for the upper triangles with the mark '*'.
		{
			for(k=0;k<end_of_column;k++)
				printf("*");
		}
	
		printf("\n"); //The end of this specific row.
	
		row++;
		end_of_O_column+=2;
		end_of_column-=2;

		if(row>triangle)/*We start promote the counter of spaces needed for the '*' marks
								only in the second row that holds those marks.*/
			revach++;
		spaces--; //Before each iteration we reduce the number of spaces needed before the 'O' mark.
	}//End of while loop which prints the three upper triangles.
	

	spaces= (basis_gadol-basis)/2; //Intializing the number of spaces needed for the first row of the bottom triangle.

	if((((num1/3)-3)/4)) //The number of spaces needed is getting bigger by 1 with every 4 numbers is the serial of multiplies of 3.
	spaces+=(((num1/3)-3)/4);

	while(basis>=1)// Start a loop with number of iterations as the hight of the bottom triangle.
	{
		for(a=0;a<spaces;a++)//Printing enough spaces to bring the bottom triangle to the middle.
			printf(" ");

		for(b=0;b<basis;b++)//Printing as much '*' marks as the width of the base of the triangle.
			printf("*");

			printf("\n");//End of each row.
			basis-=2; // Before each new row we reduce the width of the base by 2, so we can get a triangle.
			spaces++;//The number of spaces getting bigger in each row.
	}

	//Intializing the counters, so we can start again the whole proccess.			
basis=0;row=0;triangle=0;revach=0;basis_gadol=0;i=0;a=0;b=0;spaces=0,num1=0;num2=0;input=0;temp1=0;temp2=0;temp3=0;
	}
}while(num_of_mistakes<5);//The program will exit after 5 mistakes in choosing from the menu options.
}