TSemaphore  MySemaphore;

void DisplayChar( int &col, int row, char c )
{
    // col is passed by reference, ie. a pointer


    // Set to display at the current position
    setLCDPosition(row, col);
    // Wait a while to enhance problems with two tasks
    // calling this function
    wait1Msec( 100 );

    // Clear current character
    displayNextLCDChar( ' ' );

    // Increment the column, wrap if we reached the end
    if( ++col == 16 )
            col = 0;

    // Display the character at the new position
    setLCDPosition(row, col);
    displayNextLCDChar( c );
    writeDebugStream("This is row: %d and col:%d and char:%c\n",row,col,c);

}
task OtherTask()
{
    int     i = 0;

    while( true )
        {
#ifdef ENABLE_SEMAPHORES
        // Lock the semaphore - we will wait so no need for a timeout
        SemaphoreLock( MySemaphore );
#endif
//        // Display the moving #
        DisplayChar( i, 0, '#' );

        // release the semaphore if we have it
        if ( bDoesTaskOwnSemaphore(MySemaphore) )
            SemaphoreUnlock(MySemaphore);

        // Sleep
        wait1Msec( 500 );
        }
}
task main()
{
    int     i = 0;

    // LCD backlight on
    bLCDBacklight = true;

    // Init the semaphore
    SemaphoreInitialize(MySemaphore);

    // Start the other task
    StartTask( OtherTask );

    // clear both lines on the LCD
    clearLCDLine(0);
    clearLCDLine(1);

    // Do our own thing
    while( true )
        {
#ifdef ENABLE_SEMAPHORES
        // Lock the semaphore - we will wait so no need for a timeout
        SemaphoreLock( MySemaphore );
#endif
        // Display the moving x
        DisplayChar(i, 1, 'x' );

        // release the semaphore if we have it
        if ( bDoesTaskOwnSemaphore(MySemaphore) )
            SemaphoreUnlock(MySemaphore);

         //Sleep
        //wait1Msec( 50 );
        }
}
