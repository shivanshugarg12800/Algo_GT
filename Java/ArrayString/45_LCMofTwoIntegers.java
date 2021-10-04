public int LCMofTwoInt(int num1, int num2) {

    int lcm=0;

    // maximum number between n1 and n2 is stored in lcm
    lcm = (num1 > num2) ? num1 : num2;

    // Always true
    while(true) {
      if( lcm % num1 == 0 && lcm % num2 == 0 ) {
          return lcm
      }
      ++lcm;
    }
  }
