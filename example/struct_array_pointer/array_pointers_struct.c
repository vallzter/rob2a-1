typedef struct Cords{
	int row;
	int col;
	bool tf;

}Cords;

Cords *set_cords(){
	bool mase_array[5][6] = {
		{1,1,1,0,1,1},
		{0,0,1,1,1,1},
		{1,1,0,0,1,1},
		{1,0,0,0,1,0},
		{1,1,1,1,1,1}};
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
	Cords *ptr = set_cords();
	for(int i=0;i<30;i++){
	writeDebugStream("Hnit %d%d%d\n",ptr->row,ptr->col,ptr->tf);
	ptr++;
}


}
