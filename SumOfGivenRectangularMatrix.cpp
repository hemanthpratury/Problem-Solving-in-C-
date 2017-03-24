
/*
*
*
* Sai Siva Hemanth Pratury 				SJSU ID:010817833
* home work 3 question-2
*/



#include <iostream>
using namespace std;

#define rows 5		//Given matrix is of order 5*6
#define cols 6

//function prototype
void precomputedSum(int givenMatrix[rows][cols],int auxilaryMatrix[rows][cols]);

// Pre computing the sum of every possible rectangle matrix and storing in an auxilary matrix which is used to find the sum of any required rectangular matrix
void precomputedSum(int givenMatrix[rows][cols], int auxilaryMatrix[rows][cols])
{
	//int i,j,k;
	
	
	
//int auxilaryMatrix[][] = new int[givenMatrix.length][givenMatrix[0].length];
auxilaryMatrix[0][0] = givenMatrix[0][0]; 

for(int i=1;i<rows;i++){	//first row
	auxilaryMatrix[i][0] = auxilaryMatrix[i-1][0] + givenMatrix[i][0];
}

for(int j=1;j<cols;j++){		//first col
	auxilaryMatrix[0][j] = auxilaryMatrix[0][j-1] + givenMatrix[0][j];
}

//alother rows and cols
for(int i=1; i<rows;i++) {		
	for(int j=1; j<cols;j++) {
		auxilaryMatrix[i][j] = givenMatrix[i][j] 
								+	auxilaryMatrix[i][j-1] 
								+	auxilaryMatrix[i-1][j]
								-	auxilaryMatrix[i-1][j-1];
}
}
};

int reqRectangleSum(int auxilaryMatrix[rows][cols], int TL_X, int TL_Y, int BR_X,int BR_Y)
{
// TL_X = top left X coordiate		 & 			TL_Y = top left Y coordiate
// BR_X = botom right X coordiate 	 &		    BR_Y = bottom right Y coordiate of the required rectangular region

    int sum = auxilaryMatrix[BR_X][BR_Y];

    if (TL_X > 0)
       sum = sum - auxilaryMatrix[TL_X-1][BR_Y];

    if (TL_Y > 0)
       sum = sum - auxilaryMatrix[BR_X][TL_Y-1];

    if (TL_X > 0 && TL_Y > 0)
       sum = sum + auxilaryMatrix[TL_X-1][TL_Y-1];

    return sum;
}

int main()
{
	int givenMatrix[rows][cols] = {{1, 2, 3, 4, 5, 6},
						{2, 4, 7, 3, 2, 1},
						{3, 9, 3, 1, 1, 4},
						{4, 8, 6, 5, 5, 3},
						{5, 2, 1, 4, 7, 8}};
	int auxilaryMatrix[rows][cols];
	precomputedSum(givenMatrix,auxilaryMatrix);
	int TL_X = 1, TL_Y = 1, BR_X = 4, BR_Y = 3;
   cout << "Sum of the rectangular givenMatrix is: " << reqRectangleSum(auxilaryMatrix, TL_X, TL_Y, BR_X, BR_Y) << endl;
}

