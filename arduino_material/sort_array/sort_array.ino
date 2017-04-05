byte numbers[] = {1,2,55,25,80,75,129};

void setup()
{
 Serial.begin(9600);

 printArray(numbers, sizeof(numbers)); 
 isort(numbers, sizeof(numbers));
 printArray(numbers, sizeof(numbers)); 
}

//Bubble sort my ar*e
void isort(byte *a, int n)
{
 for (int i = 1; i < n; ++i)
 {
   int j = a[i];
   int k;
   for (k = i - 1; (k >= 0) && (j < a[k]); k--)
   {
     a[k + 1] = a[k];
   }
   a[k + 1] = j;
 }
}

//what it says on the tin
void printArray(byte *a, int n)
{
 for (int i = 0; i < n; i++)
 {
   Serial.print(a[i], DEC);
   Serial.print(' ');
 }
 Serial.println();
}

//we'll not use loop for this
void loop()
{
}
