/*----------------------------------------------------------------------------------------------------*\                                   *|
|*                                                                                                    *|
|*  This is a recursive drivefunction, for repeating action  																					*|                                       *|                       *|
\*----------------------------------------------------------------------------------------------------*/

int drive_recursive(int dist){
	if(dist > 20000){
		return 0;
	}
	writeDebugStream("Keyri : %d \n", dist);
	dist = dist * 2;
	return drive_recursive(dist);
}
