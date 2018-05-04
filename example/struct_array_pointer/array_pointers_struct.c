/*
Create a struct contaning x,y cordinates and a bool tf showing
true if way is open or closed.
*/

typedef struct Cords{
	int row;
	int col;
	bool tf;

}Cords;
/*
function of type Cords pointer with 2D arry creating a grid that the robot
will follow tf way
*/
Cords *set_cords(){
	bool mase_array[5][6] = {
		{1,1,1,0,0,0},
		{0,0,1,1,1,0},
		{0,0,0,0,1,0},
		{0,0,0,0,1,0},
		{0,0,0,0,1,0}};
	/*Create an array of type Cords and a pointer that points to addresses
		witch holds structs of type Cords and return it
	*/
	Cords r[30];
	int l=0;
	for(int k=0;k<5;k++){
		for(int j=0;j<6;j++){
			r[l].row =k;
			r[l].col =j;
			r[l].tf = mase_array[k][j];
			l++;
		}
	}
	return &r;

};

task main()
{
	/*
	Pointer  of type Cords that points to an array of Cords
	*/
	Cords *ptr = set_cords();
	//showing the path to the end of the grid
	for(int i=0;i<30;i++){
		if(ptr->tf){
	writeDebugStream("Hnit %d%d%d\n",ptr->row,ptr->col,ptr->tf);

}
// make the pointer trawell throug  the array from one address to an other
ptr++;
}

}
