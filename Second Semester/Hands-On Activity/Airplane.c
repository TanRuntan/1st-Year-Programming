#include<stdio.h>
#include<ctype.h>

struct plane
{
	int row;
	char seat;
	int asgn;
};

struct plane seats[5][4];

void displane_seats (struct plane seats[5][4])
{
	printf("\nPlane Seats Display:");
	printf("\n\tA\tB\tC\tD\t\n");
	
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", i + 1);
		
		for(int j = 0; j < 4; j++)
		{
			if(seats[i][j].asgn)
				printf("\tX ");
			else
				printf("\t%c ", seats[i][j].seat);
		}		
		printf("\n");
	}
}

int main()
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			seats[i][j].row = i + 1;
			seats[i][j].seat = 'A' + j;
			seats[i][j].asgn = 0;
		}
	}
	
	displane_seats(seats);
	
	int asgn_seats = 0;
	int total_seats = 5 * 4;
	
	while(asgn_seats < total_seats)
	{
		int row;
		char seat;
		
		printf("\nEnter the seat desired");
		printf("\n\t Row Number (1-5): ");
		if(scanf("%d", &row) != 1)
		{
			printf("\n\t[Invalid input for row. Please try again.]\n");
			while(getchar() != '\n')
				continue;
			continue;
		}
		
		if(row < 1 || row > 5)
		{
			printf("\n\t[Invalid input for row. Please try again.]\n");
			continue;
		}
		
		printf("\n\t Seat Letter (A-D): ");
		if(scanf(" %c", &seat) != 1)
		{
			printf("\n\t[Invalid input for seat. Please try again.]\n");
			while (getchar() != '\n')
				continue;
			continue;
		}	
		
		seat = toupper(seat);
		int index_seats = seat - 'A';
		
		if(index_seats < 0 || index_seats >= 4)
		{
			printf("\n\t[Invalid input for seats. Please try again.]\n");
			continue;
		}
		
		if(seats[row - 1][index_seats].asgn)
		{
			printf("\n\t[The seat is already occupied. Please choose another seat.]\n");
			continue;
		}
		
		seats[row - 1][index_seats].asgn = 1;
		asgn_seats++;
		
		displane_seats(seats);
	}
	
	printf("\n\t[All seats are filled. Thank you!]\n");
	
}