int max = 40;
int dist1 = 275;
void myCode()
{
  //----------------------------------------------------------------------------------------
  // myCode();
  //
  // This is the tab where the programming of your vehicle operation is done.
  // Tab _00_AEV_key_words contains a compiled list of functions/subroutines used for vehicle
  // operation. 
  //
  // Note:
  // (1) After running your AEV do not turn the AEV off, connect the AEV to a computer, or 
  //     push the reset button on the Arduino. There is a 13 second processing period. In 
  //     post processing, data is stored and battery recuperation takes place. 
  // (2) Time, current, voltage, total marks, position traveled are recorded approximately 
  //     every 60 milliseconds. This may vary depending on the vehicles operational tasks. 
  //     It takes approximately 35-40 milliseconds for each recording. Thus when programming,
  //     code complexity may not be beneficial. 
  // (3) Always comment your code. Debugging will be quicker and easier to do and will 
  //     especially aid the instructional team in helping you. 
  //---------------------------------------------------------------------------------------- 

  // Program between here-------------------------------------------------------------------
  //Set motor to 100
  
  int delay = 6.9;
  //Set forward
  reverse(4);
  goDist(dist1,520);
  brake(4); 
  goFor(delay);
  motorSpeed(4,20);
  goFor(3);
  brake(4); 
  // And here--------------------------------------------------------------------------------

 // DO NOT REMOVE. end of void myCode()
  
}
void goDist(int dist, int target){
  motorSpeed(4,max);
  int total = getForwardsTotal();
  int start = getForwardsTotal();
  while(total < dist){
    byte s = map(total,start,dist,40,0);
    motorSpeed(4,s);
    total = getForwardsTotal();
  }
  boolean isStopped = false;
  int xF = 0;
  while(!isStopped){
      int xI = xF;
      delay(500);
      xF = getVehiclePosition();
      int v = xI-xF;
      if(v == 0){
        isStopped = true;
      }
  }
  //if(getVehiclePosition() != target){
   // motorSpeed(4,20);
   // goToAbsolutePosition(target);
  //}
  brake(4);
}

int getVehiclePosition(){
  return getVehiclePostion();
}




