
task main()
{
	int var =2001;
	int *ptr=NULL;
	int **ptr2=NULL;
	ptr=&var;
	ptr2=&ptr;
	writeDebugStream("This is the value of var:%d\n", var);
  writeDebugStream("This is the address of var;%d\n", &var);
  writeDebugStream("This is the value of ptr;%d\n", *ptr);
  writeDebugStream("This is the address of ptr;%d\n", ptr);
  writeDebugStream("This is the address of ptr2;%d\n", ptr2);
	writeDebugStream("This is the value of ptr2;%d\n", **ptr2);
	writeDebugStream("This is the address of ptr;%d\n", &ptr);

}
