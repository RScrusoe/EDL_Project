
long randNumber;
void def()
{
  randNumber = random(10);
}


int maxNum(int x[], int xsize)
{
  int i = 0;
//  int max_val =*x;
  int max_val = x[0];
  for (i = 0;i<xsize;i++)
  {
     max_val = max(max_val,x[i]);
 //    Serial.print("Current value x[i]: ");
//    Serial.print(*(x+i));
//    Serial.print("\tCurrent max_val: ");
//    Serial.println(max_val);
//    max_val =  ((max_val)>( *(x+i) )?(max_val):( *(x+i) ));
  }
  return max_val;
}

int minNum(int x[], int xsize)
{
  int i = 0;
  //  int max_val =*x;
  int min_val = x[0];
  for (i = 0; i < xsize; i++)
  {
    min_val = min(min_val, x[i]);
  }
  return min_val;
}
