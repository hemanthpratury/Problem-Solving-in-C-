Write the code of an algorithm to execute a click and paint function as in windows Paint program. The
paint target is represented as a matrix and lines are 1 while non-colored spaces are represented as 0.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Author: Sai Siva Hemanth Pratury
Student ID: 010817833
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//defining a 10*10 matrix boundaries
#define row 3
#define col 4

//function performing the paint operation (filling the zeros in the specified region(click) with 1's)
void paint_program(int givenMatrix[3][4], int x, int y)
{
	if (x <= 0 || x >= row || y <=0 || y >= col){
	if(givenMatrix[x][y]==0){
	cerr<<"No Proper Boundary found";
exit(0);}
}

if(givenMatrix[x][y]!=0){
return;
}

	givenMatrix[x][y] = 1;
	paint_program(givenMatrix, x+1, y);
	paint_program(givenMatrix, x-1, y);
	paint_program(givenMatrix, x, y+1);
	paint_program(givenMatrix, x, y-1);
}


int main()
{
	int givenMatrix[row][col] = {0,1,1,0,
			      1,0,0,1,
			      0,1,1,0};
					
	paint_program(givenMatrix,1, 1);
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		cout << givenMatrix[i][j] << " ";
		cout << endl;
	}
}
