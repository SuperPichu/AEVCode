int max = 40;
int dist = 345;
int dist2 = 370;
int dist3 = 378;
int dist4 = 380;
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
  goDist(dist);
  brake(4); 
  goFor(delay);
  goDist(dist2);
  brake(4);
  goFor(delay);
  reverse(4);
  goDistRev(dist3);
  brake(4); 
  goFor(delay);
  brake(4); 
  goDistRev(dist4);
  brake(4);
  // And here--------------------------------------------------------------------------------

 // DO NOT REMOVE. end of void myCode()
  
}
void goDist(int dist){
  int total = getTotalMarks();
  int start = getTotalMarks();
  dist = dist+start;
  motorSpeed(4,max);
  while(total < dist){
    byte s = map(total,start,dist,40,0);
    motorSpeed(4,s);
    total = getTotalMarks();
  }
  delay(3000);
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
  brake(4);
}

void goDistRev(int dist){
  int total = getTotalMarks();
  int start = getTotalMarks();
  dist = dist+start;
  motorSpeed(4,max);
  while(total < dist){
    byte s = map(total,start,dist,40,30);
    motorSpeed(4,s);
    total = getTotalMarks();
  }
  brake(4);
  delay(3000);
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
  brake(4);
}


int getVehiclePosition(){
  return getVehiclePostion();
}




